#include <iostream>
#include <vector>
using namespace std;

// the idea is not to look for sum of the elements of the subsets
// the idea is to check if the element is included or not
// if not included, sum will beas it is
// if included, sun]btract that ele from sum
// return 1 for all the subsets in which sum has become 0
// TC : O(2^n)

int count(vector<int>v,int n,int sum)
{
    if(n==0)
    {
        if(sum==0)
        return 1;
        else
        return 0;
    }
    return count(v,n-1,sum) + count(v,n-1,sum-v[n-1]);
}

int main()
{
    vector<int>v{10,5,2,6,3};
    int n=v.size();
    int sum=8;
    cout<<count(v,n,sum)<<endl;
    return 0;
}