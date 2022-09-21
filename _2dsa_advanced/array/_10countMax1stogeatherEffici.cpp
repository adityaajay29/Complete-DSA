#include <iostream>
#include <vector>
using namespace std;

// approach : start counting with 0, and res=0
// when found a 0 ele, make the count as 0
// again start count and update the result as max of res and count

int max1s(vector<int>v,int n)
{
    int count=0;
    int res=0;
    for(int i=0;i<n;i++)
    {
        if(v[i]==0)
        {
            count=0;
        }
        else 
        {
            count++;
            res=max(res,count);
        }
    }
    return res;
}

int main()
{
    vector<int>v{1,0,1,1,0,0,1,1,1,0};
    int n=v.size();
    cout<<"max 1s togeather are "<<max1s(v,n)<<endl;
    return 0;
}