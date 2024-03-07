#include<iostream>
using namespace std;
int main()
{
    pair<int,string> p;

    p=make_pair(2,"xyz");
    pair<int,string> &p1=p;
    //p1=p;
    p1.first=3;
    //p={2,"xyz"}
    cout<< p1.first<<" "<<p1.second<<endl;
    return 0;
}
