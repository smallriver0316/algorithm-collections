#include <iostream>
#include <cmath>
using namespace std;

int getNextPrime(bool *flags, int n, int next)
{
  int i;
  for (i = next; i < n; i++)
  {
    if (flags[i])
    {
      break;
    }
  }
  return i;
}

void crossOff(bool *flags, int n, int prime)
{
  // delete all multiple numbers of prime
  // it can be assumed that numbers of k * prime have already been deleted.
  // k < prime
  for (int i = prime * prime; i < n; i += prime)
  {
    flags[i] = false;
  }
}

void sieveOfEratosthenes(bool *flags, int n)
{
  int prime = 2;
  while (prime <= sqrt(n - 1))
  {
    // delete all multiple numbers of prime
    crossOff(flags, n, prime);

    // search next true number
    prime = getNextPrime(flags, n, prime + 1);
  }
}

int main()
{
  int t;
  cin >> t;

  int n = t + 1;
  bool flags[n];

  // initialize
  // 0 and 1 are not prime.
  flags[0] = false;
  flags[1] = false;
  for (int i = 2; i < n; i++)
  {
    flags[i] = true;
  }

  sieveOfEratosthenes(flags, n);

  for (int i = 0; i < n; i++)
  {
    if (flags[i])
    {
      cout << i << ", ";
    }
  }
  cout << endl;

  return 0;
}
