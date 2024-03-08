 // Problem set 2 
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
// problem: 25/a 
#include <iostream>

using namespace std;

int find_different_evenness(int arr[], int n) {
    bool has_even = false, has_odd = false;

    for (int i = 0; i < n; ++i) {
        if (arr[i] % 2 == 0) {
            has_even = true;
        } else {
            has_odd = true;
        }

        // Early exit if both even and odd numbers are found
        if (has_even && has_odd) {
            return -1;
        }
    }

    // Return index of first even or odd element (1-based indexing)
    for (int i = 0; i < n; ++i) {
        if ((arr[i] % 2 == 0 && !has_even) || (arr[i] % 2 == 1 && !has_odd)) {
            return i + 1;
        }
    }

    // Shouldn't reach here (all elements have same evenness)
    return -1;
}

int main() {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int different_index = find_different_evenness(arr, n);

    if (different_index == -1) {
        cout << "All numbers have the same evenness" << endl;
    } else {
        cout << "The number at index " << different_index << " differs in evenness" << endl;
    }

    return 0;
}
// problem: 1772A
/*expr will hold "3+5".
expr[0] will be '3' (ASCII code 51).
expr[0] - '0' will be 51 - 48 = 3, storing the digit 3 in a.*/
#include <iostream>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t; // Read the number of test cases

    while (t--) {
        string expr;
        cin >> expr;

        // Extract digits using string manipulation
        int a = expr[0] - '0';
        int b = expr[2] - '0';

        // Evaluate and print the sum
        cout << a + b << endl;
    }

    return 0;
}

// problem: 1829B
#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t; // Read the number of test cases

    while (t--) {
        int n;
        cin >> n; // Read the length of the array

        int a[n];
        cin >> a[0]; // Read the first element separately

        int currentBlankLength = 0;
        int maxBlankLength = 0;

        for (int i = 1; i < n; ++i) {
            cin >> a[i]; // Read remaining elements

            // Update based on current element
            currentBlankLength = a[i] == 0 ? currentBlankLength + 1 : 0; // Add 1 if 0, reset to 0 if 1

            // Update max length if needed
            maxBlankLength = max(maxBlankLength, currentBlankLength);
        }

        cout << maxBlankLength << endl;
    }

    return 0;
}

//problem: 148A 
#include <iostream>
#include <set> // Include set for handling unique values

using namespace std;

int main() {
    int k, l, m, n, d;

    // Read input values
    cin >> k >> l >> m >> n >> d;

    // Set to store unique multiples
    set<int> affectedDragons;

    // Add multiples of each factor
    for (int i = 1; i <= d; ++i) {
        if (i % k == 0) {
            affectedDragons.insert(i); // Add if divisible by k
        }
        if (i % l == 0 && i % k != 0) { // Only add if not already added due to k
            affectedDragons.insert(i); // Add if divisible by l (excluding duplicates from k)
        }
        if (i % m == 0 && i % k != 0 && i % l != 0) { // Exclude duplicates from k and l
            affectedDragons.insert(i); // Add if divisible by m (excluding duplicates)
        }
        if (i % n == 0 && i % k != 0 && i % l != 0 && i % m != 0) { // Exclude all previous factors
            affectedDragons.insert(i); // Add if divisible by n (excluding all prior duplicates)
        }
    }

    // Print the total number of affected dragons (unique values)
    cout << affectedDragons.size() << endl;

    return 0;
}

//problem: 1389A 
#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t; // Read the number of test cases

    while (t--) {
        int l, r;
        cin >> l >> r; // Read l and r

        // Check if finding x and y is possible
        if (2 * l <= r) {
            cout << l << " " << 2 * l << endl; // x = l, y = 2 * l
        } else {
            cout << -1 << " " << -1 << endl; // No solution exists
        }
    }

    return 0;
}

//problem: maths 

#include <iostream>
using namespace std;

// Function to count the number of lucky digits (4s and 7s) in an integer
int countLuckyDigits(int num) {
    int count = 0;
    while (num > 0) {
        int digit = num % 10;
        if (digit == 4 || digit == 7) {
            count++;
        }
        num /= 10;
    }
    return count;
}

// Function to check if a number is lucky (contains only 4s and 7s)
bool isLucky(int num) {
    while (num > 0) {
        int digit = num % 10;
        if (digit != 4 && digit != 7) {
            return false;
        }
        num /= 10;
    }
    return true;
}

int main() {
    long long n;
    cin >> n;

    int luckyDigitCount = countLuckyDigits(n);
    if (isLucky(luckyDigitCount)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}

//25A 
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int evenCount = 0, oddCount = 0;
    int evenIndex = -1, oddIndex = -1;

    for (int i = 1; i <= n; ++i) {
        int num;
        cin >> num;

        if (num % 2 == 0) {
            evenCount++;
            evenIndex = i;
        } else {
            oddCount++;
            oddIndex = i;
        }
    }

    if (evenCount == 1) {
        cout << evenIndex << "\n";
    } else {
        cout << oddIndex << "\n";
    }

    return 0;
}

//1389 A
#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int l, r;
        cin >> l >> r;

        if (2 * l <= r) {
            cout << l << " " << 2 * l << endl;
        } else {
            cout << -1 << " " << -1 << endl;
        }
    }

    return 0;
}

//1829B
#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t; // Number of test cases

    while (t--) {
        int n;
        cin >> n; // Length of the array

        int maxBlankSpace = 0;
        int currentBlankSpace = 0;

        for (int i = 0; i < n; ++i) {
            int ai;
            cin >> ai; // Read array element

            if (ai == 0) {
                currentBlankSpace++;
            } else {
                maxBlankSpace = max(maxBlankSpace, currentBlankSpace);
                currentBlankSpace = 0;
            }
        }

        // Update maxBlankSpace again (in case it extends to the end)
        maxBlankSpace = max(maxBlankSpace, currentBlankSpace);

        cout << maxBlankSpace << "\n";
    }

    return 0;
}

//148A
#include <iostream>
using namespace std;

int main() {
    int k, l, m, n, d;
    cin >> k >> l >> m >> n >> d; // Read input values

    int damagedDragons = 0;

    for (int dragon = 1; dragon <= d; ++dragon) {
        if (dragon % k == 0 || dragon % l == 0 || dragon % m == 0 || dragon % n == 0) {
            damagedDragons++;
        }
    }

    cout << damagedDragons << "\n";

    return 0;
}

//266A
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n; // Number of stones

    string s;
    cin >> s; // Colors of the stones

    int damagedStones = 0;
    for (int i = 1; i < n; ++i) {
        if (s[i] == s[i - 1]) {
            damagedStones++;
        }
    }

    cout << damagedStones << "\n";

    return 0;
}

//520A
#include <iostream>
#include <string>
#include <cctype> // For isalpha()

using namespace std;

bool isPangram(const string& str) {
    int alphabet[128] = {0}; // Use a larger array to accommodate more characters

    for (char ch : str) {
        // Convert all characters to lowercase for case-insensitive comparison
        ch = tolower(ch);

        // Check if the character is a valid letter
        if (isalpha(ch)) {
            alphabet[ch]++; // Update the count for the corresponding character
        }
    }

    // Check if all letters (with at least one occurrence) have a count of at least 1
    for (int count : alphabet) {
        if (count > 0) { // Consider letters with at least one occurrence
            return false; // Not a pangram if any letter appears more than once
        }
    }

    return true; // It's a pangram if only unique letters appear (all counts are zero)
}

int main() {
    string str;
    getline(cin, str);

    if (isPangram(str)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}

//
