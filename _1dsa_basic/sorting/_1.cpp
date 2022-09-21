#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int arr[]={10,20,5,7};
    sort(arr,arr+4,greater<int>());
    for(auto x:arr)
    cout<<x<<" ";
    cout<<endl;
    return 0;
}