#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    string str;
    map<string,int>m; 
    for(int i=0;i<t;i++)
    {
        cin>>str;
        m[str]++;
    }
    for(auto mp :m)
    {
        cout<<mp.first<<" "<<mp.second<<"\n";
    }
    cout<<"sorted in increasing order based on its value.\n";
    //Multimap is similar to a map with an addition that multiple elements can have the same keys
    multimap<int,string>m1;
    for(auto mp :m)
    {
        m1.insert({mp.second,mp.first});
    }
    for(auto mp1 : m1)
    {
        cout<<mp1.second<<" "<<mp1.first<<"\n";
    }
    return 0;
}