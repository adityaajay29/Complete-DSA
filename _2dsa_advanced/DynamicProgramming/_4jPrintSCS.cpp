#include <iostream>
using namespace std;

int dp[1001][1001];
    
    void lcs(string &s1, string &s2, int m, int n)
    {
        for(int i=0;i<=m;i++)
        {
            for(int j=0;j<=n;j++)
            {
                if(i == 0 || j == 0)
                    dp[i][j] = 0;
            }
        }
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(s1[i-1] == s2[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    
    string shortestCommonSupersequence(string str1, string str2) {
        int m=str1.size();
        int n=str2.size();
        lcs(str1, str2, m, n);
        int i=m;
        int j=n;
        // for(int i=0;i<=m;i++)
        // {
        //     for(int j=0;j<=n;j++)
        //     {
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        string supersequence="";
        while(i > 0 && j > 0)
        {
            if(str1[i-1] == str2[j-1])
            {
                supersequence.push_back(str1[i-1]);
                i--;
                j--;
            }
            else
            {
                if(dp[i-1][j] > dp[i][j-1])
                {
                    supersequence.push_back(str1[i-1]);
                    i--;
                }
                else
                {
                    supersequence.push_back(str2[j-1]);
                    j--;
                }
            }
            // else
            // {
            //     if(dp[i][j-1] > dp[i-1][j])
            //     {
            //         supersequence.push_back(str2[j-1]);
            //         j--;
            //     }
            //     else
            //     {
            //         supersequence.push_back(str1[i-1]);
            //         i--;
            //     }
            // }
        }
        while(i > 0)
        {
            supersequence.push_back(str1[i-1]);
            i--;
        }
        while(j > 0)
        {
            supersequence.push_back(str2[j-1]);
            j--;
        }
        reverse(supersequence.begin(), supersequence.end());
        return supersequence;
    }

    int main()
    {
        string str1, str2;
        // bbbaaaba
        // bbababbb
        cin>>str1>>str2;
        cout<<shortestCommonSupersequence(str1, str2)<<endl;
        return 0;
    }