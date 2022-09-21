#include <iostream>
#include <vector>
using namespace std;

// problem : 
// Ninja is planing this ‘N’ days-long training schedule.
//  Each day, he can perform any one of these three activities :
// (Running, Fighting Practice or Learning New Moves).
//  Each activity has some merit points on each day. 
// As Ninja has to improve all his skills, he can’t do the same activity in two consecutive days. 
// Can you help Ninja find out the maximum merit points Ninja can earn?
// You are given a 2D array of size N*3 ‘POINTS’ 
// with the points corresponding to each day and activity. 
// Your task is to calculate the maximum number of merit points that Ninja can earn.

// ex : 
// If the given ‘POINTS’ array is [[1,2,5], [3 ,1 ,1] ,[3,3,3] ],
// the answer will be 11 as 5 + 3 + 3.

// here, changing variables are days and prevTask
// dp[days][4];

int solve(vector<vector<int> > &days, int day, int prevTask, vector<vector<int> > &dp)
{
    int maxPoints = 0;
    if(day == 0)
    {
        for(int currTask=0;currTask<3;currTask++)
        {
            if(currTask != prevTask)
            {
                maxPoints = max(maxPoints, days[0][currTask]);
            }
        }
        return maxPoints;
    }
    
    if(dp[day][prevTask] != -1)
        return dp[day][prevTask];
    
    for(int currTask=0;currTask<3;currTask++)
    {
        if(currTask != prevTask)
        {
            //                                 tell the left of the ele that you performed currTask
            int points = days[day][currTask] + solve(days, day-1, currTask, dp);
            maxPoints = max(maxPoints, points);
        }
    }
    return dp[day][prevTask] = maxPoints;
}

int main()
{
    int n;
    cin>>n;
    vector<vector<int> > days;
    int currTask = n;
    int a, b, c;
    while(currTask--)
    {
        cin>>a>>b>>c;
        vector<int> temp{a, b, c};
        days.push_back(temp);
    }
    vector<vector<int> > dp(n, vector<int> (4, -1));
    cout<<"the max points is "<<solve(days, n-1, 3, dp)<<endl;
    return 0;
}