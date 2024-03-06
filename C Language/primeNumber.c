
// PRIME NUMBER = number greater than 1 that has exactly two distinct positive divisors: 1 and itself...2, 3, 5, 7, 11, 13, 17, 19, 23, 29, ... 

// 0 & 1 are not considered prime numbers, so c is set to 0, indicating a non-prime number.

//i = 2: Starting value for the loop counter, as 1 is not considered prime.

//if (c == 1): Checks the value of c. If it's still 1 (meaning no divisors were found in the loop), n is prime.

#include <stdio.h>

int main() {

  int n, i, c = 1;
  printf("Enter a positive integer: ");
  scanf("%d", &n);

  if (n == 0 || n == 1)
    c = 0; // not prime

  for (i = 2; i <= n / 2; i++) {

    if (n % i == 0) {
      c = 0; // not prime
      break;
    }
  }
  if (c == 1)
    printf("%d is a prime number.", n);
  else
    printf("%d is not a prime number.", n);

  return 0;
}
