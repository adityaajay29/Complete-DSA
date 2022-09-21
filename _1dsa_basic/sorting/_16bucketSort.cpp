#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// concept of hashing and threading
// O(n) if number of bucket elements are in range of elements in that bucket
// works best among all if elements are uniformly distribted, i.e., n/k elements in each buckets
// example : if k buckets, and each buckets have elements distributed between range
// and number of elements in that bucket is also in that range, then O(n) time
// else O(n2)

void bucketSort(int arr[],int n,int k)
{
    // finding largest ele
    int largest=0;
    for(int i=1;i<n;i++)
    {
        if(arr[i]>arr[largest])
        largest=i;
    }
    int maxEle=arr[largest];
    // increasing largest by 1
    maxEle++;
    // creating vector of k buckets
    vector<int>buckets[k];
    // filling the buckets with values in particular range of that bucket
    for(int i=0;i<n;i++)
    {
        int bucketIndex=k*arr[i]/maxEle;
        buckets[bucketIndex].push_back(arr[i]);
    }
    // sorting elements of each buckets
    for(int i=0;i<k;i++)
    sort(buckets[i].begin(),buckets[i].end());
    int ind=0;
    // combining all buckets
    for(int i=0;i<k;i++)
    {
        for(int j=0;j<buckets[i].size();j++)
        arr[ind++]=buckets[i][j];
    }
}

int main()
{
    int arr[]={30,40,10,80,12,70};
    bucketSort(arr,6,5);
    for(auto x:arr)
    cout<<x<<" ";
    cout<<endl;
    return 0;
}