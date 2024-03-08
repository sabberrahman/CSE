#include <iostream>

using namespace std;

/**
 * Calculates the sum of natural numbers from 1 to n (inclusive) using recursion.
 *
 * Args:
 *   n: The upper limit of the range (positive integer).
 *
 * Returns:
 *   The sum of natural numbers from 1 to n.
 */
int sumOfRange(int n) {
  if (n == 1) {
    return 1; // Base case: sum of 1 is 1
  } else {
    return n + sumOfRange(n - 1); // Recursive case: sum(n) = n + sum(n-1)
  }
}

int main() {
  int n;

  cout << "Recursion: Calculate the sum of numbers from 1 to n\n";

  cout << "Input the last number of the range starting from 1: ";
  cin >> n;

  int sum = sumOfRange(n);

  cout << "\nThe sum of numbers from 1 to " << n << " is: " << sum << endl;

  return 0;
}
// fibonacci
#include <stdio.h>

int fibonacci(int n) {
    if (n <= 1) {
        return n;  // Base case: F(0) = 0, F(1) = 1
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);  // Recursive case: F(n) = F(n-1) + F(n-2)
    }
}

int main() {
    int n, i;

    printf("Enter the number of terms of the Fibonacci Series: ");
    scanf("%d", &n);

    printf("Fibonacci Series: ");
    for (i = 0; i < n; i++) {
        printf("%d ", fibonacci(i));
    }

    printf("\n");
    return 0;
}

//The division sizeof(arr) / sizeof(arr[0]) calculates the total number of elements in the array by dividing the entire array size by the size of each element.
