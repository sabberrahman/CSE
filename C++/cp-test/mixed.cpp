#include <iostream>

using namespace std;

int main() {
    int k, n, w;

    // Input: cost of first banana, initial money, and number of bananas
    cin >> k >> n >> w;

    // Calculate total cost using arithmetic series formula
    int total_cost = (k * w * (w + 1)) / 2;

    // Check if the soldier has enough money
    int money_to_borrow = 0;
    if (total_cost > n) {
        money_to_borrow = total_cost - n;
    }

    // Output: money to borrow (0 if sufficient)
    cout << money_to_borrow << endl;

    return 0;
}
//problem: 2
#include <iostream>

using namespace std;

bool is_nearly_lucky(int &n) {
    int count = 0;
    while (n > 0) {
        int digit = n % 10;
        if (digit == 4 || digit == 7) {
            ++count;
        }
        n /= 10;
    }
    return count;
}

int main() {
    int n;
    cin >> n;
   int x = is_nearly_lucky(n);
    if (x == 1) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}