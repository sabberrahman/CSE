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

//