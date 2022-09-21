#include <iostream>
#include <vector>
using namespace std;

vector<int>intersection(vector<int>arr1,vector<int>arr2)
{
    vector<int>ans;
    int i=0;
    int j=0;
    int n1=arr1.size();
    int n2=arr2.size();
    while(i<n1 && j<n2)
    {
        if(i>0 && arr1[i]==arr1[i-1])
        {
            i++;
            continue;
        }
        else if(j>0 && arr2[j]==arr2[j-1])
        {
            j++;
            continue;
        }
        else if(arr1[i]<arr2[j])
        {
            ans.push_back(arr1[i]);
            i++;
        }
        else if(arr2[j]<arr1[i])
        {
            ans.push_back(arr2[j]);
            j++;
        }
        else
        {
            ans.push_back(arr1[i]);
            i++;
            j++;
        }
    }
    while(i<n1)
    {
        if(i==0 || arr1[i]!=arr1[i-1])
        {
            ans.push_back(arr1[i]);
        }
        i++;
    }
    while(j<n2)
    {
        if(j==0 || arr2[j]!=arr2[j-1])
        {
            ans.push_back(arr2[j]);
        }
        j++;
    }
    return ans;
}

int main()
{
    vector<int>arr1{2,5,10,10,15};
    vector<int>arr2{3,4,4,5,8,16,16};
    vector<int>ans=intersection(arr1,arr2);
    for(auto x:ans)
    cout<<x<<" ";
    cout<<endl;
    return 0;
}