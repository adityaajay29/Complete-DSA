#include <iostream>
using namespace std;

// dp[i][j][evaluateTo]
int dp[101][101][101];

int solve(string &s, int i, int j, bool evaluateTo)
{
    // base case 1
    if(i > j)
    return false;

// base case 2 : when either T or F left
    if(i == j)
    {
        if(evaluateTo == true)
        return s[i] == 'T';
        else 
        return s[i] == 'F';
    }
    int ans = 0;
    // we can initialise k with k+1(operator)
    // k can go till n-2, as it will be last operator
    // k += 2 as operator will be at distance of 2
    for(int k=i+1;k<j;k+=2)
    {
        // temp answers : 
        int leftTrue = solve(s, i, k-1, true);
        int leftFalse = solve(s, i, k-1, false);
        int rightTrue = solve(s, k+1, j, true);
        int rightFalse = solve(s, k+1, j, false);

        // function to solve the final ans from tempans 
        // check the operater at index k
        if(s[k] == '|')
        {
            // if evaluating to true
            if(evaluateTo == true)
            ans += (leftTrue * rightTrue) + (leftTrue * rightFalse) + (leftFalse * rightTrue);
            // if evaluating to false
            else
            ans += (leftFalse * rightFalse);
        }
        else if(s[k] == '&')
        {
            if(evaluateTo == true)
            ans += (leftTrue * rightTrue);
            else
            ans += (leftTrue * rightFalse) + (leftFalse * rightFalse) + (leftFalse * rightTrue);
        }
        else if(s[k] == '^')
        {
            if(evaluateTo == true)
            ans += (leftTrue * rightFalse) + (leftFalse * rightTrue);
            else
            ans += (leftTrue * rightTrue) + (leftFalse * rightFalse);
        }
    }
    return ans;
}

int main()
{
    string s = "T|T&F^T";
    // There are 4 ways
    // ((T|T)&(F^T)), (T|(T&(F^T))), (((T|T)&F)^T) and
    // (T|((T&F)^T))
    cout<<"the no of ways to evaluate true are "<<solve(s, 0, s.size()-1, true)<<endl;
    return 0;
}