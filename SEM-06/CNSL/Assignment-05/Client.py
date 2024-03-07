import socket
import pickle
from cryptography.hazmat.primitives import serialization
from cryptography.hazmat.primitives.asymmetric import padding
from cryptography.hazmat.primitives import hashes

from cryptography.hazmat.backends import default_backend
from RSA import RSA_encrypt


with open("client_private_key.pem", "rb") as key_file:
    client_private_key = serialization.load_pem_private_key(
    key_file.read(),
    password=b'PICT',
    backend=default_backend() 
    )



def sign_data(private_key, data):
    signature = private_key.sign(
    data,
    padding.PSS(
    mgf=padding.MGF1(hashes.SHA256()),
    salt_length=padding.PSS.MAX_LENGTH
    ),
    hashes.SHA256()
    )
    return signature

SERVER_ADDRESS = "10.10.12.219"
client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client_socket.connect((SERVER_ADDRESS, 12345))


p = 53
q = 59
message=int(input("Enter encrpt msg (int):"))
print(message)
message = RSA_encrypt(p, q, message)

print(message)
data = {"message": message }

client_socket.sendall(pickle.dumps(data))
response = client_socket.recv(1024)
print(response.decode())
client_socket.close()