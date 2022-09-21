#include <iostream>
#include <vector>
using namespace std;

int mergeNcount(vector<int>arr,int l,int mid,int h)
{
    int n=arr.size();
    int n1=mid-l+1;
    int n2=h-mid;
    vector<int>left(n1,0);
    vector<int>right(n2,0);
    for(int i=0;i<n1;i++)
    {
        left[i]=arr[l+i];
    }
    for(int i=0;i<n2;i++)
    {
        right[i]=arr[mid+1+i];
    }
    vector<int>ans(n1+n2,0);
    int i=0;
    int j=0;
    int k=l;
    int res=0;
    while(i<n1 && j<n2)
    {
        if(left[i]<=right[j])
        {
            ans[k++]=left[i++];
        }
        else if(right[j]<left[i])
        {
            ans[k++]=right[j++];
            res+=(n1-i);
        }
    }
    while (i<n1)
    {
        ans[k++]=left[i++];
    }
    while(j<n2)
    {
        ans[k++]=right[j++];
    }
    return res;
}

int countInversions(vector<int>arr,int l,int h)
{
    int res=0;
    if(l<h)
    {
        int mid=(l+h)/2;
        res+=countInversions(arr,l,mid);
        res+=countInversions(arr,mid+1,h);
        res+=mergeNcount(arr,l,mid,h);
    }
    return res;
}

int main()
{
    vector<int>arr{2,5,8,11,3,6,9,13};
    int l=0;
    int h=arr.size()-1;
    cout<<"total inversions in this array are "<<countInversions(arr,l,h)<<endl;
    return 0;
}