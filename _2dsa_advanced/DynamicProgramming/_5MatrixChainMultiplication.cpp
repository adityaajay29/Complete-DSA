#include <iostream>
#include <vector>
using namespace std;

int mcm(vector<int> &arr, int i, int j)
{
    // base case:
    // if size of array == 0 
    // or, arr has single ele, then also not valid, as matrix dimension requires 2 ele
    // [Ai] = (a)i-1 * (a)i
    if(i >= j)
    return 0;

    // range for k
    // two possibilities : 
    // a :
    // k starts from i, and goes till j-1
    // then two divisions : (i to k) and (k+1 to j);

    // we have to get min cost for mcm,and for each call it will be initialised to int_max
    int ans=INT_MAX;

    for(int k=i;k<j;k++)
    {
        // for any 2 matrices, multiplication will involve the i-1th ele, kth ele and jth ele
        int multi = arr[i-1] * arr[k] * arr[j];
        int temp = mcm(arr, i, k) + mcm(arr, k+1, j) + multi;
        ans = min(ans, temp);
    }
    return ans;
}

int main()
{
    vector<int> arr;
    int n, val;
    cin>>n;
    int i=n;
    while(i--)
    {
        cin>>val;
        arr.push_back(val);
    }
    cout<<"the min cost of mcm is "<<mcm(arr, 1, n-1)<<endl;
    return 0;
}