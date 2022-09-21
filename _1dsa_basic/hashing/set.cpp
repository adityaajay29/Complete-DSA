#include <iostream>
#include <set>
using namespace std;

// time complexity of O(logn)
// only unique keys allowed, no duplicates

int main()
{
    set<int>s;
    int arr[]={23,7,90,87,43};
    for(int i=0;i<5;i++)
    {
        s.insert(arr[i]);
    }
    for(auto x:s)
    cout<<x<<" ";
    cout<<endl;
    for(auto it=s.rbegin();it!=s.rend();it++)
    cout<<*it<<" ";
    cout<<endl;
    if(s.find(7)!=s.end())
    cout<<*s.find(7)<<endl; //find returns iterator to the address of 7,not value 7, so * use for dereffering
    else
    cout<<"not found"<<endl;
    s.erase(87);
    cout<<s.size()<<" is the size of set"<<endl;    
    return 0;
}