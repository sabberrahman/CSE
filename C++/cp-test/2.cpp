#include <iostream>
#include <string>
 
using namespace std;
 
int main() {
 
    string a, b;
    cin >> a >> b;
 
   int sizeA = a.length();
   int sizeB = b.length();
 
    if(sizeA > sizeB) cout << "1";
    else if(sizeA < sizeB) cout << "-1";
    else cout << "0";
}