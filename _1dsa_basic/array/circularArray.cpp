#include <iostream>
#include <vector>
using namespace std;

int main()
{
    string arr[]={"a","b","c","d","e","f"};
    int n=sizeof(arr)/sizeof(arr[0]);
    int index;
    cout<<"enter the index to start printing"<<endl;
    cin>>index;
    // for(int i=index;i<index+n;i++)
    // {
    //     cout<<arr[i%n]<<"->";
    // }
    // cout<<endl;
    int i=index;
    while(i<index+n)
    {
        cout<<arr[i%n]<<"->";
        i++;
    }
    cout<<endl;
    return 0;
}