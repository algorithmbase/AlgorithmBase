// Source: http://www.algorithmbase.com
// Date: 2011/07/04
// Read: http://www.algorithmbase.com/191/c-program-for-prime-number-checking/
#include <stdio.h>

// This function returns 1 if N is prime, 0 otherwise.
char isPrime(int n) {
   int i = 0;
   
   if (n < 2) {
      // Make sure we capture the cases when
      // * N is negative
      // * N is 0 or 1 (both 0 and 1 are not prime)
      return 0;
   }
   
   // We only increase i up to the square root of N.
   for (i = 2; i * i <= n; i++) {
      if (n % i == 0) { // If I divides N, then N is not prime.
         return 0;
      }
   }
   
   // N is prime, because we did not find any number
   // between 1 and N - 1 that divides N.
   return 1;
}

int main() {
   int n;
   
   scanf("%d", &n);
   
   if (isPrime(n)) {
      printf("%d is prime.\n", n);
   } else {
      printf("%d is not prime.\n", n);
   }
   
   return 0;
}