#include<iostream>
using namespace std;
int main()
{
    int a[]={1,2,3};
    int b[]={4,5,6};
    pair<int,int> p[3];
    p[0]={1,4};
    p[1]={2,5};
    p[2]={3,6};
    swap(p[0],p[2]);
    for(int i=0;i<3;i++)
    {
        cout<<p[i].first<<" "<<p[i].second<<endl;

    }
}
