# Diffie-Hellman-Key-Exchange
Diffie Hellman Key Exchange written in C++. Shared password is outputted as hex.

This is a text-based application. Please enter the number keys to navigate the menus.

Instructions:
1. Between yourself and User 2, agree upon Public Key #1 and Public Key #2 (your base and modulus number)
2. Enter your private key. This key is not to be shared with anyone
3. After entering your private key, the program will provide a Shared Key. Give your Shared Key to User 2. User 2 will do the same and give their Shared Key to User 1 (you).
4. Once you enter User 2's shared key, the program will output the Shared Password. This Shared Password will be the same for User 2, once they enter your Shared Key.


Notes:
- Only numeric inputs are valid
- Your base number (Public Key #1) is recommended to be a prime number (primitive root modulo n)
- Your modulus number (Public Key #2) is recommended to be a large prime number
