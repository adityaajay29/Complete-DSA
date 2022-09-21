#include <iostream>
#include <vector>
using namespace std;

// naive approach
// TC : O(n2)
int Max1sTogeather(vector<int>v,int n)
{
    int count=0;
    for(int i=0;i<n;i++)
    {
        int curr=0;
        for(int j=i;j<n;j++)
        {
            if(v[j])
            {
                curr++;
            }
            else 
            break;
        }
        count=max(count,curr);
    }
    return count;
}

int main()
{
    vector<int>v{0,1,1,1,1,0,1,1,1,0};
    int n=v.size();
    cout<<"max consecutive 1s are "<<Max1sTogeather(v,n)<<endl;
    return 0;
}
