import socket
import pickle
from cryptography.hazmat.primitives import serialization
from cryptography.hazmat.primitives.asymmetric import padding
from cryptography.hazmat.primitives import hashes
from RSA import RSA_decrypt


with open('server_private_key.pem', 'rb') as key_file:
    server_private_key = serialization.load_pem_private_key(
        key_file.read(),
        password=b'PICT'
    )


def verify_signature(public_key, data, signature):
    try:
        print(public_key, data, signature)
        public_key.verify(
            signature,
            data,
            padding.PSS(
                mgf=padding.MGF1(hashes.SHA256()),
                salt_length=padding.PSS.MAX_LENGTH
            ),
            hashes.SHA256()
        )
        return True
    except:
        return False

SERVER_ADDRESS = "10.10.12.219"
server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server_socket.bind((SERVER_ADDRESS, 12345))
server_socket.listen(1)

print("Server is listening...")

while True:
    conn, addr = server_socket.accept()
    print("Connected by", addr)
    data = conn.recv(4096)
    if not data:
        break
    data = pickle.loads(data)
    
    message = data["message"]

    p = 53
    q = 59
    print("Encrypted message is", message)
    message = RSA_decrypt(p, q, message)
    print("Decrypted message is", message)
    conn.close()