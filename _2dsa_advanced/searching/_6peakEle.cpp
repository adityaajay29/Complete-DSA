#include <iostream>
#include <vector>
using namespace std;

int peakEle(vector<int>arr,int n)
{
    if(n==1 || arr[0]>=arr[1])
    return arr[0];
    for(int i=1;i<n-1;i++)
    {
        if(arr[i]>=arr[i-1] && arr[i]>=arr[i+1])
        return arr[i];
    }
    return arr[n-1];
}

int main()
{
    vector<int>arr{5,12,10,34,24,1};
    int n=arr.size();
    cout<<"the peak ele is "<<peakEle(arr,n)<<endl;
    return 0;
}