#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// problem:
// https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/jungle-run/

int m,n;
char grid[31][31];
int visited[31][31];
int dist[31][31];
vector<int>dx{-1,0,0,1};
vector<int>dy{0,1,-1,0};

bool isValid(int x,int y)
{
    if(x<1 || x>m || y<1 || y>n)
    return false;
    if(visited[x][y] || grid[x][y]=='T')
    return false;

    return true;
}

int shotestPath(int x,int y)
{
    visited[x][y]==1;
    dist[x][y]==0;
    queue<pair<int,int> >q;
    q.push({x,y});
    while(!q.empty())
    {
        int xSt=q.front().first;
        int ySt=q.front().second;
        q.pop();
        for(int i=0;i<4;i++)
        {
            if(isValid(x+dx[i],y+dy[i]))
            {
                int xNext=x+dx[i];
                int yNext=y+dy[i];
                if(grid[xNext][yNext]=='E')
                return dist[xNext][yNext];
                visited[xNext][yNext]==1;
                dist[xNext][yNext]=1+dist[xSt][ySt];
                q.push({xNext,yNext});
            }
        }
    }
}