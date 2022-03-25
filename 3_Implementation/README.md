# Implementation of Encryption & Decryption using RSA

* Write the function named for prime, ce(ciphering for e), cd(ciphering for d), encryption and decryption
* **prime** function must return
    * First try dividing it by 2, and see if you get a whole number.
    * A prime number can be divided, without a remainder, only by itself and by 1.
* **ce** function must return
    * Choose e such that e > 1 and coprime to totient which means gcd (e, totient) must be equal to 1, e is the public key.
* **cd** function must return
    * Choose d such that it satisfies the equation de = 1 + k (totient), d is the private key not known to everyone.
* Cipher text is calculated using the equation c = m^e mod n where m is the message.
* With the help of c and d we decrypt message using equation m = c^d mod n where d is the private key.
* **encrypt** function must return
    * Return the encrypted message after ciphering
* **decrypt** function must return
    * Return the decrypted message after ciphering.
* The function must not use any printf and scanf functions.
* Supporting functions can be used to read and print data to and from console.
