#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

void arrayInput(int *arr,int &n)
{
    cout<<"enter n"<<endl;
    cin>>n;
    cout<<"enter the array elements"<<endl;
    for(int i=0;i<n;i++)
    cin>>arr[i];
}

int main()
{
    int arr[100];
    int n;
    arrayInput(arr,n);
    unordered_map<int,int>umap;
    for(int i=0;i<n;i++)
    umap[arr[i]]++;
    for(auto x:umap)
    cout<<x.first<<" "<<x.second<<endl;
    // vector<int>v;
    // for(auto x:umap)
    // v.push_back(x.second);
    // for(auto x:v)
    // cout<<x<<" ";
    cout<<endl;    
    return 0;
}




// int main()
// {
//     unordered_map<int,int>freq;
//     vector<int>v{2,3,5,2,3,6,4,8,5,1,0,3,2,0,4,2,1};
//     for(auto it:v)
//     freq[it]++;
//     for(auto x:freq)
//     {
//         if(x.second>1)
//         cout<<x.first<<endl;
//     }
//     return 0;
// }