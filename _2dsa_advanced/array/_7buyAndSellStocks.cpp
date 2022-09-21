#include <iostream>
#include <vector>
using namespace std;

// problem is to look for all stocks,buy and sell and return total profit
// ex: {1,5,3,8,12}
// total profit=(5-1)+(8-3)+(12-8)=13

int totalProfit(vector<int>v,int n)
{
    int totalProfit=0;
    for(int i=1;i<n;i++)
    {
        // when price goes high, sell it
        // when price is low, buy it
        if(v[i]>v[i-1])
        {
            totalProfit+=(v[i]-v[i-1]);
        }
    }
    return totalProfit;
}

int main()
{
    vector<int>v{1,5,3,8,12};
    int n=v.size();
    cout<<"the total profit is "<<totalProfit(v,n)<<endl;
    return 0;
}
