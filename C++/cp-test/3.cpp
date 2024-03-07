/* input -- saBBER RAHmaA
output -- SABBER RHAMAN

INPUT-- SAbber rahmAN
output--sabber rahman */
#include <bits/stdc++.h>

using namespace std;

int main (){

   string word;
   getline(cin , word);

    
      int uppercase_count = 0, lowercase_count = 0;
    for (int i = 0; word[i] != '\0'; i++) {
        if (isupper(word[i])) {
            uppercase_count++;
        } else if (islower(word[i])) {
            lowercase_count++;
        }
    }

    bool make_uppercase = uppercase_count > lowercase_count;

    for (int i = 0; word[i] != '\0'; i++) {
        if (make_uppercase) {
            word[i] = toupper(word[i]);
        } else {
            word[i] = tolower(word[i]);
        }
    };

    cout << word ; 

    return 0;
    
}