#include <iostream>
#include <vector>
using namespace std;

bool dfs(vector<int>list[],vector<int>&visited,int i,int parent)
{
    visited[i]=1;
    for(auto x : list[i])
    {
        if(!visited[x])
        {
            // parent of x is i
            if(dfs(list,visited,x,i))
            return true;
        }
        // if already visited is not parent, return true,i.e., cycle present
        else if(x!=parent)
        return true;
    }
    return false;
}

bool detectCycle(vector<int>list[],int vertices)
{
    vector<int>visited(vertices+1,0);
    for(int i=1;i<=vertices;i++)
    {
        if(!visited[i])
        {
            // initial parent is assigned as -1
            if(dfs(list,visited,i,-1))
            return true;
        }
    }
    return false;
}

void graph(vector<int>list[],int u,int v)
{
    list[v].push_back(u);
    list[u].push_back(v);
}

int main()
{
    int vertices;
    int edges;
    cout<<"enter no of vertices and edges"<<endl;
    cin>>vertices>>edges;
    vector<int>list[vertices+1];
    for(int i=0;i<edges;i++)
    {
        int u,v;
        cout<<"enter connections ";
        cin>>u>>v;
        graph(list,u,v);
    }
    cout<<detectCycle(list,vertices)<<endl;
    return 0;
}