#include <iostream>
#include <vector>
using namespace std;

int largest(int arr[],int n)
{
    int result=0;
    for(int i=1;i<n;i++)
    {
        if(arr[i]>arr[result])
        result=i;
    }
    return arr[result];
}

void freqTable(int arr[],int n,vector<int>&newTable)
{
    int result=largest(arr,n);
    for(int i=0;i<=result;i++)
    {
        newTable.push_back(0);
    }
    for(int i=0;i<n;i++) //traversing the given array from start to end 0 to n-1, and looking for the elements
    {
        newTable[arr[i]]++;
    }
}

int main()
{
    int arr[]={1,2,3,4,5,6,3,2,1,1,2,3,4};
    int n=13;
    cout<<"the given array is ";
    for(int i=0;i<n;i++)
        {
            cout<<arr[i]<<" ";
        }
    cout<<endl;
    vector<int>newTable;
    cout<<"largest element is "<<largest(arr,n)<<endl;
    freqTable(arr,n,newTable);
    cout<<"the Frequency table is ";
    for(int i=0;i<newTable.size();i++)
        {
            cout<<newTable[i]<<" ";
        }
    cout<<endl;
    vector<int>ans;
    for(int i=0;i<newTable.size();i++)
    {
        if(newTable[i]>1)
        ans.push_back(i);
    }
    if(ans.size()==0)
    return {-1};
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}
