from math import gcd


def RSA_encrypt(p: int, q: int, message: int) -> int:
    
    n = p * q


    t = (p - 1) * (q - 1)

   
    for i in range(2, t):
        if gcd(i, t) == 1:
            e = i
            break

    
    ct = (message ** e) % n
    return ct

def RSA_decrypt(p: int, q: int, ct: int) -> int:
   
    n = p * q

    
    t = (p - 1) * (q - 1)

   
    for i in range(2, t):
        if gcd(i, t) == 1:
            e = i
            break

    
    j = 0
    while True:
        if (j * e) % t == 1:
            d = j
            break
        j += 1


    mes = (ct ** d) % n
    return mes




