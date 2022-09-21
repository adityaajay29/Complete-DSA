#include <iostream>
using namespace std;

int dp[101][10001];

int eggdrop(int e, int f)
{
    if(f == 0 || f == 1)
    return f;

    if(e == 1)
    return f;

    if(dp[e][f] != -1)
    return dp[e][f];

    int ans = INT_MAX;
    int l=1;
    int h=f;
    while(l<=h)
    {
        int mid = (l+h)/2;
        int breaks = eggdrop(e-1, mid-1);
        int notBreaks = eggdrop(e, f-mid);
        int worstCase = 1 + max(breaks, notBreaks);
        ans = min(ans, worstCase);
        if(breaks < notBreaks)
        l = mid+1;
        else
        h = mid-1;
    }
    return dp[e][f] = ans;
}

int main()
{
    int e, f;
    cin>>e>>f;
    memset(dp, -1, sizeof(dp));
    cout<<"the min no of attempts of dropping eggs to find the critical floor is "<<eggdrop(e, f)<<endl;
}