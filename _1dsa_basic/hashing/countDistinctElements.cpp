#include <iostream>
#include <unordered_set>
// #include<vector>
using namespace std;

int main()
{
    int n;
    int arr[100];
    cout<<"enter n"<<endl;
    cin>>n;
    cout<<"enter array"<<endl;
    for(int i=0;i<n;i++)
    cin>>arr[i];
    unordered_set<int>s;
    for(int i=0;i<n;i++)
    s.insert(arr[i]);
    cout<<"the count of distint elements is "<<s.size()<<" "<<endl;
    return 0;
}