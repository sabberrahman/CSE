// 1858A
#include <iostream>

using namespace std;

string whoWins(int a, int b, int c) {
  // Calculate the total number of buttons.
  int totalButtons = a + b + c;

  // Check if the total number of buttons is odd.
  if (totalButtons % 2 == 1) {
    // If odd, the first player (Anna) has an advantage and wins.
    return "First";
  } else {
    // If even and both players have buttons (a or b is not zero),
    // it's a draw (they can keep canceling each other's moves).
    if (a > 0 || b > 0) {
      return "Draw";
    }
    // If even and only common buttons (a and b are zero),
    // the second player (Katie) loses.
    else {
      return "Second";
    }
  }
}

int main() {
  int t;
  cin >> t;

  for (int i = 0; i < t; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    string winner = whoWins(a, b, c);
    cout << winner << endl;
  }

  return 0;
}

//460A
#include <iostream>

using namespace std;

int daysUntilNoSocks(int n, int m) {
  // Days used for existing socks (including the first day).
  int daysUsedExisting = min(n, m - 1);

  // Calculate the number of sock purchases before Vasya runs out.
  int numPurchases = (n - daysUsedExisting) / m;

  // Total days covered by existing socks and purchases.
  int totalDays = daysUsedExisting + numPurchases * m;

  return totalDays;
}

int main() {
  int n, m;
  cin >> n >> m;

  int days = daysUntilNoSocks(n, m);
  cout << days << endl;

  return 0;
}

//25 A
#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;

  int numbers[n];
  for (int i = 0; i < n; i++) {
    cin >> numbers[i];
  }

  // Check if the first number is even (no remainder when divided by 2)
  bool isFirstEven = (numbers[0] % 2 == 0);

  // Loop through remaining numbers, starting from the second
  for (int i = 1; i < n; i++) {
    // If current number's evenness differs from the first, it's the different one
    if (numbers[i] % 2 != isFirstEven) {
      cout << "The number that differs in evenness is at index " << i + 1 << "." << endl;
      return 0; // Exit after finding the different number
    }
  }

  // If loop completes, all numbers have the same evenness
  cout << "All numbers have the same evenness." << endl;

  return 0;
}

//580A
#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;

  int income[n];
  for (int i = 0; i < n; i++) {
    cin >> income[i];
  }

  // Track current and maximum subsegment lengths
  int currentLength = 1;
  int maxLength = 1;

  for (int i = 1; i < n; i++) {
    // Check if current day's income is non-decreasing
    if (income[i] >= income[i - 1]) {
      currentLength++;
    } else {
      // Update maxLength if current subsegment is longer
      maxLength = max(maxLength, currentLength);
      // Reset currentLength for a new subsegment
      currentLength = 1;
    }
  }

  // Update maxLength in case the last subsegment is longest
  maxLength = max(maxLength, currentLength);

  cout << maxLength << endl;

  return 0;
}

//233
#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;

  // Special case: no perfect permutation for n = 1
  if (n == 1) {
    cout << -1 << endl;
    return 0;
  }

  int permutation[n];
  for (int i = 0; i < n; i++) {
    permutation[i] = (i + 1) * i;
  }

  // Print the perfect permutation
  for (int i = 0; i < n; i++) {
    cout << permutation[i] << " ";
  }
  cout << endl;

  return 0;
}

// MATH SECTIONS 
//1A
#include <iostream>

using namespace std;

int main() {
  int n, m, a;
  cin >> n >> m >> a;

  // Flagstones needed in a row (without rounding)
  int rows = n / a;
  // Flagstones needed in a column (without rounding)
  int columns = m / a;

  // Extra space left uncovered in rows
  int extraRowSpace = n % a;

  // Extra space left uncovered in columns
  int extraColSpace = m % a;

  // Total number of flagstones (without considering extra space)
  int totalFlagstones = rows * columns;

  // If there's extra space in a row, we need one more flagstone
  if (extraRowSpace > 0) {
    rows++;
  }

  // If there's extra space in a column, we need one more flagstone
  if (extraColSpace > 0) {
    columns++;
  }

  // Update total flagstones considering extra space
  totalFlagstones = rows * columns;

  cout << totalFlagstones << endl;

  return 0;
}

//1873B
#include <iostream>

using namespace std;

int main() {
  int t;
  cin >> t; // Number of test cases

  while (t--) {
    int n;
    cin >> n; // Number of digits

    int a[n];
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }

    // Calculate original product
    int product = 1;
    for (int i = 0; i < n; i++) {
      product *= a[i];
    }

    // Find the best digit to increase (and its index)
    int best_digit_index = -1;
    for (int i = 0; i < n; i++) {
      int temp_product = product * (a[i] + 1);
      if (temp_product > product) {
        product = temp_product;
        best_digit_index = i;
      }
    }

    // Increase the best digit by 1 (optional, for verification)
    if (best_digit_index != -1) {
      a[best_digit_index]++;
    }

    // Return the maximum product
    cout << product << endl;
  }

  return 0;
}

//
