#include <iostream>
#include <vector>
using namespace std;

// problem : there is a grid of size m*n
// '#' represents wall and '.' represents room space
// count no of rooms

int m,n;
int visited[10001][10001];
char grid[10001][10001];
vector<int>dx{-1,0,0,1};
vector<int>dy{0,1,-1,0};

bool isValid(int x,int y)
{
    if(x<1 || x>m || y<1 || y>n)
    return false;
    if(visited[x][y] || grid[x][y]=='#')
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

int roomsCount()
{
    int count=0;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(!visited[i][j] && grid[i][j]=='.')
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
    cout<<"the number of rooms are "<<roomsCount()<<endl;

                                    // 5 8
                                    
                                    // ########
                                    // #..#...#
                                    // ####.#.#
                                    // #..#...#
                                    // ########

                                    // the number of rooms are 3

    return 0;
}