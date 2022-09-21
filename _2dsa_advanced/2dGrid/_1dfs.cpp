#include <iostream>
using namespace std;

int m,n;
int visited[1001][1001];

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
    // for going up
    if(isValid(x-1,y))
    dfs(x-1,y);
    // for going right
    if(isValid(x,y+1))
    dfs(x,y+1);
    // for going left
    if(isValid(x,y-1))
    dfs(x,y-1);
    // for going down 
    if(isValid(x+1,y))
    dfs(x+1,y);
}

int main()
{
    cin>>m>>n;
    dfs(1,1);
    return 0;
}