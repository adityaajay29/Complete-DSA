// TC : O(n2)
#include <iostream>
#include <vector>
using namespace std;

// approach : keep track of max from left and max from right for all the elements 
// calculate the amount of water that can bec stored from bar 2nd to 2nd last using left and right max
// TC : O(n)
// SC : O(n)
int maxWater(vector<int>v,int n)
{
    int trapped=0;
    vector<int>leftMax(n,0);
    vector<int>rightMax(n,0);
    leftMax[0]=v[0];
    for(int i=1;i<n;i++)
    {
        leftMax[i]=max(v[i],leftMax[i-1]);
    }
    rightMax[n-1]=v[n-1];
    for(int j=n-2;j>=0;j--)
    {
        rightMax[j]=max(v[j],rightMax[j+1]);
    }
    for(int i=1;i<n-1;i++)
    {
        trapped+=(min(leftMax[i],rightMax[i])-v[i]);
    }
    return trapped;
}

int main()
{
    vector<int>v{2,1,5,1,2,3,1};
    int n=v.size();
    cout<<"max trapped water is "<<maxWater(v,n)<<endl;
    return 0;
}