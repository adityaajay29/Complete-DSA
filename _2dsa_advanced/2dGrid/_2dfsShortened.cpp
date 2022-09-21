#include <iostream>
#include <vector>
using namespace std;

int m,n;
int visited[1001][1001];
vector<int>dx{-1,0,0,1};
vector<int>dy{0,1,-1,0};

bool isValid(int x,int y)
{
    if(x<1 || x>m || y<1 || y>n)
    return false;
    if(visited[x][y])
    return false;

    return true;
}

void dfs(int x,int y)
{
    visited[x][y]=1;
    cout<<x<<" "<<y<<endl;
    for(int i=0;i<4;i++)
    {
        if(isValid(x+dx[i],y+dy[i]))
        dfs(x+dx[i],y+dy[i]);
    }
}

int main()
{
    cin>>m>>n;
    cout<<"the dfs traversal of grid for cell(x,y) is"<<endl;
    dfs(1,1);
    return 0;
}