#include <iostream>
#include <vector>
using namespace std;

int solve(vector<vector<int> > &days, vector<vector<int> > &dp)
{
    int n = days.size();
    // initialising 
    dp[0][0] = max(days[0][1], days[0][2]);
    dp[0][1] = max(days[0][0], days[0][2]);
    dp[0][2] = max(days[0][0], days[0][1]);
    dp[0][3] = max(days[0][0], max(days[0][1], days[0][2]));

    for(int day=1;day<n;day++)
    {
        for(int last=0;last<4;last++)
        {
            dp[day][last] = 0;
            for(int task=0;task<3;task++)
            {
                if(task != last)
                {
                    dp[day][last] = max(dp[day][last], days[day][task] + dp[day-1][task]);
                }
            }
        }
    }
    return dp[n-1][3];
}

int main()
{
    int n;
    cin>>n;
    vector<vector<int> > days;
    int i = n;
    int a, b, c;
    while(i--)
    {
        cin>>a>>b>>c;
        vector<int> temp{a, b, c};
        days.push_back(temp);
    }
    vector<vector<int> > dp(n, vector<int> (4, 0));
    cout<<"the max points is "<<solve(days, dp)<<endl;
    return 0;
}