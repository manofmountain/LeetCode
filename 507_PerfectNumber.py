#Let's consider the problem of finding the sum of all divisors of N.

#Consider the prime factorization of N, for example suppose it was 2^a * 3^b * 5^c... Every divisor is going to be some 2^i 3^j 5^k... for i in [0,a], j in [0,b] etc. The sum of all of these is simply (2^0 + 2^1 + ... + 2^a) * (3^0 + 3^1 + ... + 3^b) * (5^0 + 5^1 + ... + 5^c) * ... .

#How might we find the prime factorization of N? This is a standard technique worth learning.

#Look at our function prime_factorization, which is defined for positive integers. Our loop invariant is: d will be the least number that N might be #divisible by. We'll divide out factors of d and record the number of such divisions as the exponent of d in the prime factorization of N. Since we #have checked all numbers before it and divided them out of N, d will always be prime. After checking all potential primes <= sqrt(N), if N > 1 then #it must be prime, and we should record that too.
#We should also be careful to remember that negative N's are always not perfect.

def prime_factorization(N):
  d = 2
  while d * d <= n:
    expo = 0
    while N % d == 0:
      expo += 1
      N /= d
    if expo:
      yield (d, expo)
    d += 1
  if N > 1:
    yield (N, 1)

ans = 1
for prime, expo in prime_factorization(abs(N)):
  ans *= sum(prime ** k for k in xrange(expo + 1))
return ans == 2*N