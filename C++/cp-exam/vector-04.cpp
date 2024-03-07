#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<pair<int,int>> v;
    v={{1,2},{3,4},{5,6}};
    v.push_back(make_pair(7,8));
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i].first<<" "<<v[i].second<<endl;

    }

    v.push_back(make_pair(7,8));
    cout<<v[3].first<<" "<<v[3].second<<endl;
    cout<< v.size()<<endl;
    return 0;


}
