#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "primes.h"
t_primes	g_prime_list = { 0 };

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
char		is_prime(long number)
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

void		sieve_of_eratosthenes(long limit)
{
  char		*primes;
  long		prime_optimization = (long)lround(sqrtl(limit)) + 1;
  long		prime_count = limit - 2; //0 and 1 are not primes, so substract them

  //Allocate an array for all numbers in limit - 0 means not prime, 1 means prime
  //In C: false == 0; true is any number not equal to 0
  primes = malloc(limit * sizeof(char));
  //Suppose all of them are prime
  memset(primes, 1, limit * sizeof(char));

  //Eliminate none-primes
  primes[0] = 0;
  primes[1] = 0;
  //Go through array of numbers and eliminate multiples - the none primes
  for (long i = 2; i < prime_optimization; i++)
    {
      if (primes[i])
	{
	  //Set all multiples to false
	  for (long j = i * i; j < limit; j += i)
	    {
	      if (primes[j])
		{
		  primes[j] = 0;
		  prime_count--;
		}
	    }
	}
    }

  if (g_prime_list.length != 0)
    free(g_prime_list.primes);
  g_prime_list.limit_used = limit;
  g_prime_list.length = prime_count;
  g_prime_list.primes = malloc(prime_count * sizeof(long));
  long j = 0;
  for (long i = 0; i < limit; i++)
    {
      if (primes[i])
	{
	  g_prime_list.primes[j] = i;
	  j++;
	}
    }

  free(primes);
}
