#include <iostream>
#include <vector>
using namespace std;

// very important *****
// recursively calls dfs for the adjecents of a vertex
// O(v+e), v is for worst case, when all the vertex comprise a disconnected components

// applications:
// path finding
// maze puzzles
// cycle detection
// topological sorting
// strongly connected components

void graph(vector<int>list[],int u,int v)
{
    list[u].push_back(v);
    list[v].push_back(u);
}

void dfs(vector<int>list[],vector<int>&visited,int i)
{
    visited[i]=1;
    cout<<i<<" ";
    for(auto x:list[i])
    {
        if(visited[x]==0)
        {
            dfs(list,visited,x);
        }
    }
}

void dfsComponents(vector<int>list[],int vertices)
{
    vector<int>visited(vertices+1,0);
    for(int i=1;i<=vertices;i++)
    {
        if(visited[i]==0)
        {
            dfs(list,visited,i);
        }
    }
}

int main()
{
    int edges,vertices,u,v;
    cout<<"enter no of vertices ";
    cin>>vertices;
    cout<<"enter no of edges ";
    cin>>edges;
     vector<int>list[vertices+1];
    for(int i=0;i<edges;i++)
    {
        cout<<"enter connection ";
        cin>>u>>v;
        graph(list,u,v);
    }
    for(int i=1;i<=vertices;i++)
    {
        for(auto x:list[i])
        cout<<i<<"->"<<x<<" ";
        cout<<endl;
    }
    cout<<"the dfs traversal is ";
    dfsComponents(list,vertices);
    return 0;
}