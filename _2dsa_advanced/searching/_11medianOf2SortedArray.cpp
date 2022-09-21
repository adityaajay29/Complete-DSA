#include <iostream>
#include <vector>
using namespace std;

vector<int> median(vector<int>arr1,vector<int>arr2,int n1,int n2)
{
    vector<int>merge(n1+n2,0);
    int i=0;
    int j=0;
    int k=0;
    while(i<n1 && j<n2)
    {
        if(arr1[i]<=arr2[j])
        {
            merge[k++]=arr1[i++];
        }
        else
        {
            merge[k++]=arr2[j++];
        }
    }
    while(i<n1)
    merge[k++]=arr1[i++];
    while(j<n2)
    merge[k++]=arr2[j++];
    int n3=merge.size();
    return merge;
}

int main()
{
    vector<int>arr1{10,20,30,40,50};
    vector<int>arr2{5,15,25,35,45,55,65,75,85};
    int n1=arr1.size();
    int n2=arr2.size();
    vector<int>ans=median(arr1,arr2,n1,n2);
    for(auto x:ans)
    cout<<x<<" ";
    cout<<endl;
    cout<<(float(ans[ans.size()/2])+float(ans[ans.size()/2-1]))/2;
    return 0;
}  