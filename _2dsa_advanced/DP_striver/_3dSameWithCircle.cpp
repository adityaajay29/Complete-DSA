#include <iostream>
#include <vector>
using namespace std;

// intution : since array is circular, we cant take both 1st and last eles
// so, solve ones by excluding last
// solve ones by excluding first
// take max of them

int solve(vector<int> &temp)
{
    int n = temp.size();
    int prev1 = temp[0];
    int prev2 = 0;
    for(int i=1;i<n;i++)
    {
        int take = temp[i];
        if(i>1)
        take += prev2;
        int notTake = prev1;
        int curr = max(take, notTake);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

int maxSumInCircle(vector<int> &arr)
{
    int n = arr.size();
    vector<int> temp1, temp2;
    for(int i=0;i<n;i++)
    {
        if(i != 0)
        temp1.push_back(arr[i]);
        if(i != n-1)
        temp2.push_back(arr[i]);
    }
    return max(solve(temp1), solve(temp2));
}

int main()
{
    vector<int> arr{5, 6, 6, 4, 7};
    int n = arr.size();
    cout<<maxSumInCircle(arr)<<endl;
    return 0;
}