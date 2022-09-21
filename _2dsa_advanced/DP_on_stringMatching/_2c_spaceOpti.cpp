#include <iostream>
#include <vector>
using namespace std;

// problem : https://leetcode.com/problems/edit-distance/

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();
        vector<int> prev(n2 + 1);
        
        prev[0] = 0;
        
        for(int j=0;j<=n2;j++)
        {
            prev[j] = j;
        }
        
        for(int i=1;i<=n1;i++)
        {
            vector<int> curr(n2 + 1, 0);
            curr[0] = i;
            for(int j=1;j<=n2;j++)
            {
                if(word1[i - 1] == word2[j - 1])
                    curr[j] = 0 + prev[j - 1];
                else 
                {
                    int ins = 1 + curr[j - 1];
                    int del = 1 + prev[j];
                    int rep = 1 + prev[j - 1];
                    curr[j] = min(min(ins, del), rep);
                }           
            }
            prev = curr;
        }
        
        return prev[n2];
    }
};