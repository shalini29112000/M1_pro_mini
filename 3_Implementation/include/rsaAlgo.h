/******************************************************************************
	RSA Algorithm
	Result reminder: ((m**e)**d) % n = m
	e: encryption, d: decryption, 
  	Encryption: ciphertext = message**e	% n
	Decryption: (c**d == (m**e)**d == m )	% n
	RSA Key Generation
	p and q, are prime numbers
	n = pq
	fi is Euler's Totient Function
	fi(n) = fi(p) * fi(q) = (p - 1) * (q - 1) = n - (p + q - 1)
	chose e, the public key:
		- 1 < e < fi(n)
		- gcd(e, fi(n)) == 1 (i.e. e and fi(n) are coprime
	chose d, the private key:
		- d == e**-1 (mod fi(n))
		-> d is the modular multiplicative inverse of e (modulo(fi(n)))
*******************************************************************************/

#ifndef __RSA__
# define __RSA__
# define RSA_SIEVE_LIMIT 255

typedef struct	s_rsa {
  long	num;
  long	fi;
  long	e;
  long	d;
} t_rsa;

t_rsa	rsa_keygen(long p, long q);// function creation

long	rsa_encrypt(long msg, long e, long num);
long	rsa_decrypt(long cyphertext, long d, long num);

#endif
