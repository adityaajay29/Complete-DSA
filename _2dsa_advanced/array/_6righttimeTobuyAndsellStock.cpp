#include <vector>
#include <iostream>
using namespace std;

int maxProfit(vector<int>v,int n)
{
    int cost=INT_MAX;
    int profit=0;
    for(int i=0;i<n;i++)
    {
        cost=min(cost,v[i]);
        profit=max(profit,v[i]-cost);
    }
    return profit;
}

int main()
{
    vector<int>v{4,5,3,8,12};
    int n=v.size();
    cout<<"the max profit will be "<<maxProfit(v,n)<<endl;
    return 0;
}