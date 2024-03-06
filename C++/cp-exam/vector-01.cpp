#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int> v={1,2,3,4,5};
    v.erase(v.begin()+2);
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" "<<endl;
    }
    return 0;
}

//1

#include<iostream>
#include<vector>
using namespace std;
int main(){
    //vector<int> *vp=new vector<int>();  dynamic allocation
    vector<int> v;// static allocation

    for(int i=0;i<10;i++)
    {
        cout<<"Capacity:"<< v.capacity()<<endl;
        cout<<"Size:"<< v.size()<<endl;

        v.push_back(i+1);
        //cout<< v.size()<<endl;
    }
    /*v.push_back(10);
    v.push_back(12);
    v.push_back(20);

    v[1]=100;
    v[3]=90; // it wont change the size
    v[4]=88;

    v.push_back(23);
    v.push_back(234);
    v.pop_back();
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<endl;
    }


    /*cout<<v[0]<<endl;
    cout<<v[1]<<endl;
    cout<<v[2]<<endl;
    cout<<v[3]<<endl;
    cout<<v[4]<<endl;
    cout<<v[5]<<endl;
    cout<<v[6]<<endl;//not safe

    cout<< "Size:" << v.size()<<endl;
    cout<< v.at(2)<<endl;
    cout<< v.at(6)<<endl;// safer
    */
}

