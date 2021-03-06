#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "primeAlgo.h"

t_primes g_prime_list = { 0 };

/**
  Greatest Common Denominator: largest number that can devide two numbers
 **/
long	gcd(long a, long b)
{
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}

/**
  Simple memory effecient way to determine if a number is prime
 **/
char	is_prime(long number)
{
  if (number < 2)
    return 0;
  for (long i = 2; i < (long)lround(sqrtl(number)) + 1; i++)
    {
      if (number % i == 0)
	return 0;
    }
  return 1;
}

/**
   Implementation of Sieve of Eratosthenes
   Will populate the global variable g_prime_list with an array of prime numbers
   up to limit, the limit used, and the number of primes found (length)
   Can be optimized by segmented sieve
 **/
void	sieve_of_eratosthenes(long limit)
{
  char		*primeALgo;
  long		prime_optimization = (long)lround(sqrtl(limit)) + 1;
  long		prime_count = limit - 2; //0 and 1 are not primes, so substract them

  //Allocate an array for all numbers in limit - 0 means not prime, 1 means prime
  //In C: false == 0; true is any number not equal to 0
  primes = malloc(limit * sizeof(char));
  //Suppose all of them are prime
  memset(primes, 1, limit * sizeof(char));

  //Eliminate none-primes
  primeAlgo[0] = 0;
  primeAlgo[1] = 0;
  //Go through array of numbers and eliminate multiples - the none primes
  for (long i = 2; i < prime_optimization; i++)
    {
      if (primeAlgo[i])
	{
	  //Set all multiples to false
	  for (long j = i * i; j < limit; j += i)
	    {
	      if (primeAlgo[j])
		{
		  primeAlgo[j] = 0;
		  prime_count--;
		}
	    }
	}
    }

  //Set global g_prime_list with primes
  //if data already set, free previouly allocated memory
  if (g_prime_list.length != 0)
    free(g_prime_list.primeAlgo);
  g_prime_list.limit_used = limit;
  g_prime_list.length = prime_count;
  g_prime_list.primeAlgo = malloc(prime_count * sizeof(long));
  long j = 0;
  for (long i = 0; i < limit; i++)
    {
      if (primeAlgo[i])
	{
	  g_prime_list.primeAlgo[j] = i;
	  j++;
	}
    }

  free(primeAlgo);
}
