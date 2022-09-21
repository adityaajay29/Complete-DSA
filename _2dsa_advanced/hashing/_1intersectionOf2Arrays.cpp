#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int intersections(vector<int>arr1,vector<int>arr2,int n1,int n2)
{
    unordered_set<int>s;
    for(int i=0;i<n1;i++)
    s.insert(arr1[i]);
    int count=0;
    for(int i=0;i<n2;i++)
    {
        if(s.find(arr2[i])!=s.end())
        {
        count++;
        s.erase(arr2[i]); 
        }
    }
    return count;
}

int main()
{
    vector<int>arr1{10,15,20,15,30,30,5};
    vector<int>arr2{30,5,30,8};
    int n1=arr1.size();
    int n2=arr2.size();
    cout<<"no of intersecting elements are "<<intersections(arr1,arr2,n1,n2)<<endl;
    return 0;
}