/**************************************************
Two prime numbers are selected as p and q
n = pq which is the modulus of both the keys.
Calculate totient = (p-1)(q-1)
Choose e such that e > 1 and coprime to totient which means gcd (e, totient) must be equal to 1, e is the public key
Choose d such that it satisfies the equation de = 1 + k (totient), d is the private key not known to everyone.
Cipher text is calculated using the equation c = m^e mod n where m is the message.
With the help of c and d we decrypt message using equation m = c^d mod n where d is the private key.
**************************************************/
#include "modAlgo.h"
#include "rsaAlgo.h"
#include "primeAlgo.h"

static long pick_e(long fi)
{
  //Ensure a list of pirmes has been generated
  //if length is 0, user didn't pass paramaters, use defined limit
  if (g_prime_list.length == 0)
    sieve_of_eratosthenes(RSA_SIEVE_LIMIT);

  for (long i = 0; i < g_prime_list.length; i++)
    {
      //This will simply pick the first, not a great idea,
      //but simple to understand algo
      if (g_prime_list.primeAlgo[i] % fi != 0 && gcd(g_prime_list.primes[i], fi) == 1)
	return g_prime_list.primes[i];
    }

  //Value must be greater than 1, so this is sufficent to indicate failure
  return 0;
}

long	rsa_encrypt(long msg, long e, long n)// for encryption of data
{
  return right_to_left(msg, e, n);
}

long	rsa_decrypt(long cyphertext, long d, long n)// for decryption of data
{
  return right_to_left(cyphertext, d, n);
}

t_rsa	rsa_keygen(long p, long q) // key exchange between cipher text
{
  t_rsa		ret = { 0 };

  //Ensure that n >= 2**b where b is the number of bits per block
  //Example if encrypting a char, 2**8 = 256, thus n >= 256
  ret.n = p * q;
  ret.fi = (p - 1) * (q - 1);
  ret.e = pick_e(ret.fi);
  ret.d = modular_inverse(ret.e, ret.fi);
  return ret;
}
