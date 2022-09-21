#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int unionCount(vector<int>arr1,vector<int>arr2,int n1,int n2)
{
    unordered_set<int>s;
    for(int i=0;i<n1;i++)
    s.insert(arr1[i]);
    for(int i=0;i<n2;i++)
    s.insert(arr2[i]);
    return s.size();
}

int main()
{
    vector<int>arr1{15,20,5,15};
    vector<int>arr2{15,15,15,20,10};
    int n1=arr1.size();
    int n2=arr2.size();
    cout<<"the union has "<<unionCount(arr1,arr2,n1,n2)<<" elements"<<endl;
    return 0;
}