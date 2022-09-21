#include <iostream>
#include <vector>
using namespace std;

// problem:
// The cells sharing common sides are counted as in the same component
// we have to find no of such cc
// similar to find cc in graph using dfs
// but here is a difference
// the grid i a binary grid, where 0 represent there is no node (invalid node), and 1 represents there is a node (valid node)
// we will call dfs or isValid func only for valid nodes

int m,n;
int visited[10001][10001];
int grid[10001][10001];
vector<int>dx{-1,0,0,1};
vector<int>dy{0,1,-1,0};

bool isValid(int x,int y)
{
    if(x<1 || x>m || y<1 || y>n)
    return false;
    // we will not consider dfs for visited cell or invalid cell, i.e., grid[x][y]==0
    if(visited[x][y] || grid[x][y]==0)
    return false;

    return true;
}

void dfs(int x,int y)
{
    visited[x][y]=1;
    for(int i=0;i<4;i++)
    {
        if(isValid(x+dx[i],y+dy[i]))
        dfs(x+dx[i],y+dy[i]);
    }
}

int connectedComponents()
{
    int count=0;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            // only checking for nodes which are valid, i.e., grid[i][j]==1
            if(!visited[i][j] && grid[i][j]==1)
            {
                count++;
                dfs(i,j);
            }
        }
    }
    return count;
}

int main()
{
    cin>>m>>n;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        cin>>grid[i][j];
    }

                                        // 6 6    

                                        // 0 0 1 0 1 1
                                        // 0 1 1 0 0 1
                                        // 0 1 0 0 0 0
                                        // 1 0 1 1 0 0
                                        // 0 0 0 1 0 0
                                        // 0 1 1 0 1 1

                                        // cc = 6

    cout<<"total connected components are "<<connectedComponents()<<endl;
    return 0;
}