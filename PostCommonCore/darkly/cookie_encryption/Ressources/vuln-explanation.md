# Cookie In Clear


## Vulnerability

There was an intriguing cookie :
```plaintext
I_am_admin=68934a3e9455fa72420237eb05902327
```

When putting it in [dcode](https://www.dcode.fr/identification-chiffrement), he found that it was encrypted in MD5 and corresponded to 'false'.

So using again [dcode](https://www.dcode.fr/hash-md5), I asked for the encryption of 'true' which gave :
```plaintext
b326b5062b2f0e69046810717534cb09
```

Changing the cookie value in the inspector tool in the storage section and the modal with the flag appeared. 

## Solution 

Do not store roles ou privileges on the client side.
Used signed tokens or ciphered ones (JWT, or a simple ID session but the check is done on the back-end server side)
Do not trust static hashes like MD5 (easy to reverse)
All verificatrions must be done on the server side with a secure database. 



