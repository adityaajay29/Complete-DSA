#include <iostream>
#include <vector>
using namespace std;

int getMaxPathSum(vector<vector<int> > &matrix)
{
    //  Write your code here.
    int n = matrix.size();
    int m = matrix[0].size();
    int maxSum = -1e9;
    vector<int> prev(m, 0);
    for(int j=0;j<m;j++)
    {
        prev[j] = matrix[0][j];
    }
    for(int i=1;i<n;i++)
    {
        vector<int> temp(m, 0);
        for(int j=0;j<m;j++)
                {
                    int up = -1e9;
                    int dl = -1e9;
                    int dr = -1e9;
                    up = prev[j];
                    if(j-1 >= 0)
                        dl = prev[j-1];
                    if(j + 1 < m)
                        dr = prev[j+1];
                    temp[j] = matrix[i][j] + max(up, max(dl, dr));
                }  
        prev = temp;
    }
    for(int j=0;j<m;j++)
    {
        maxSum = max(maxSum, prev[j]);
    }
    return maxSum;
}