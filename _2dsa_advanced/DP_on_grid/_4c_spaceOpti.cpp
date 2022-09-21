#include <iostream>
#include <vector>
using namespace std;

int solve(vector<vector<int> > &t, int n)
{
    vector<int> front(n, 0);
    for(int j=0;j<n;j++)
    {
        front[j] = t[n-1][j];
    }

    for(int i = n-2;i>=0;i--)
    {
        int m = t[i].size();
        vector<int> temp(m, 0);
        for(int j=m-1;j>=0;j--)
        {
            int up = front[j];
            int diag = front[j+1];
            temp[j] = t[i][j] + min(up, diag);
        }
        front = temp;
    }
    return front[0];
}

int main()
{
    int n;
    cin>>n;
    int u;
    vector<vector<int> >t(n, vector<int> (n,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i+1;j++)
        {
            cin>>u;
            t[i][j] = u;
        }
    }
    cout<<"min path sum is "<<solve(t, n)<<endl;
    return 0;
}