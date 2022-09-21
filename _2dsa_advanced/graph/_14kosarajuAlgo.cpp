#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void dfs(vector<int> list[], vector<int> &visited, stack<int> &s, int i)
{
    visited[i]=1;
    for(auto x:list[i])
    {
        if(!visited[x])
        dfs(list, visited, s, x);
    }
    s.push(i);
}

void revdfs(vector<int> transpose[], vector<int> &visited, int i)
{
    visited[i]=1;
    cout<<i<<" ";
    for(auto x:transpose[i])
    {
        if(!visited[x])
        revdfs(transpose, visited, x);
    }
}

int main()
{
    int n, m;
    cin>>n>>m;
    int u, v;
    vector<int> list[n+1];
    vector<int> transpose[n+1];
    while(m--)
    {
        cin>>u>>v;
        list[u].push_back(v);
        transpose[v].push_back(u);
    }
    // for(int i=1;i<=n;i++)
    // {
    //     for(auto x:list[i])
    //     cout<<i<<" "<<x<<endl;
    // }
    // for(int i=1;i<=n;i++)
    // {
    //     for(auto x:transpose[i])
    //     cout<<i<<" "<<x<<endl;
    // }
    vector<int> visited(n+1, 0);
    stack<int> s;
    for(int i=1;i<=n;i++)
    {
        if(!visited[i])
        dfs(list, visited, s, i);
    }
    for(int i=0;i<=n;i++)
    {
        visited[i]=0;
    }
    while(!s.empty())
    {
        int node=s.top();
        s.pop();
        if(!visited[node])
        {
            revdfs(transpose, visited, node);
            cout<<endl;
        }
    }
    return 0;
}