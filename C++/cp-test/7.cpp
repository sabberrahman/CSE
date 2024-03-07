#include <iostream>
#include <string>
#include <cctype> // For tolower()

using namespace std;

bool is_palindrome(const string& s) {
    int n = s.length();
    for (int i = 0; i < n / 2; ++i) {
        if (tolower(s[i]) != tolower(s[n - 1 - i])) {
            return false;
        }
    }
    return true;
}

int main() {
    string s;
    getline(cin, s); // Use getline() for safer input handling

    // Check if original string is already a palindrome
    if (is_palindrome(s)) {
        cout << "NO" << endl;
        return 0;
    }

    // Check if any single character change creates a palindrome
    int n = s.length();
    for (int i = 0; i < n; ++i) {
        string modified = s;
        // Change the current character
        modified[i] = (modified[i] == 'a' ? 'z' : modified[i] - 1);

        if (is_palindrome(modified)) {
            cout << "YES" << endl;
            return 0;
        }
    }

    // No modification works
    cout << "NO" << endl;
    return 0;
}