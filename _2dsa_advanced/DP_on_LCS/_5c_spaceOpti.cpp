#include <iostream>
#include <vector>
using namespace std;

    int minOperations(string str1, string str2) 
	{ 
	    // Your code goes here
	    int m = str1.size();
	    int n = str2.size();
	    
	    vector<int> prev(n + 1, 0);
	    
	    for(int i=1;i<=m;i++)
	    {
	        vector<int> curr(n + 1, 0);
	        for(int j=1;j<=n;j++)
	        {
	            if(str1[i - 1] == str2[j - 1])
	            curr[j] = 1 + prev[ j - 1];
	            
	            else
	            curr[j] = max(prev[j], curr[j - 1]);
	        }
	        prev = curr;
	    }
	    int lcs = prev[n];
	    int del = m - lcs;
	    int ins = n - lcs;
	    return del + ins;
	} 