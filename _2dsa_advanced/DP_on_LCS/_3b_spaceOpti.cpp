#include <iostream>
#include <vector>
using namespace std;

int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        // your code here
        vector<int> prev(m + 1);
        
        for(int j=0;j<=m;j++)
        {
            prev[j] = 0;
        }
        
        int ans = 0;

        for(int i=1;i<=n;i++)
        {
            vector<int> curr(m + 1, 0);
            for(int j=1;j<=m;j++)
            {
                if(S1[i - 1] == S2[j - 1])
                {
                    curr[j] = 1 + prev[j-1];
                    ans = max(ans, curr[j]);
                }
                else
                curr[j] = 0;
            }
            prev = curr;
        }
        return ans;
    }