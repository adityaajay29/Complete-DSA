#include <iostream>
#include <vector>
using namespace std;

int maxArea(vector<int>&height)
{
    int n=height.size();
    int res=0;
    for(int i=0;i<n;i++)
    {
        int curr=height[i];
        for(int j=i-1;j>=0;j--)
        {
            if(height[j]>=height[i]) 
            curr+=height[i];
            else 
            break;
        }
        for(int j=i+1;j<n;j++)
        {
            if(height[j]>=height[i])
            curr+=height[i];
            else
            break;
        }
        res=max(res,curr);
    }
    return res;
}

int main()
{
    vector<int>height{6,2,5,4,1,5,6};
    cout<<"the max rect area of the histographic bars is "<<maxArea(height)<<endl;
    return 0;
}
