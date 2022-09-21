#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// similar to bfg on graph
// we use queue, but here , we store x, y pair of the cocrdinates

int m,n;
int visited[10001][10001];
int dist[10001][10001];
vector<int>dx{-1,0,1,0};
vector<int>dy{0,1,0,-1};

bool isValid(int x,int y)
{
    if(x<1 || x>m || y<1 || y>n)
    return false;
    if(visited[x][y])
    return false;

    return true;
}

void bfs(int xStart,int yStart)
{
    queue<pair<int,int> >q;
    visited[xStart][yStart]=1;
    dist[xStart][yStart]=0;
    q.push({xStart,yStart});
    while(!q.empty())
    {
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        // cout<<x<<" "<<y<<endl;
        for(int i=0;i<4;i++)
        {
            if(isValid(x+dx[i], y+dy[i]))
            {
                int xNext=x+dx[i];
                int yNext=y+dy[i];
                visited[xNext][yNext]=1;
                dist[xNext][yNext]=dist[x][y]+1;
                q.push({xNext,yNext});
            }
        }
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout<<dist[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    cin>>m>>n;
    int x,y;
    cin>>x>>y;
    bfs(x,y);

                                                // 5 5
                                                // 1 1
                                                
                                                // 0 1 2 3 4 
                                                // 1 2 3 4 5 
                                                // 2 3 4 5 6 
                                                // 3 4 5 6 7 
                                                // 4 5 6 7 8 

    return 0;
}