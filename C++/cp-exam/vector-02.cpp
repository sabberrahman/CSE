#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v;
    int x = 0;
    char operation[4];

    for (int i = 0; i < n; i++)
    {
        cin >> operation;
        if (operation == "x++")
            x=x+1;
        else if (operation == "x--")
            x=x-1;
    }
    v.push_back(x);

    // Output the result
    cout << v[0] << endl;

    return 0;
}
