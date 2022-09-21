#include <iostream>
#include <vector>
using namespace std;

// dfs can be used esaily to find the sssd for TREE ***not GRAPH***, as there may be a cycle and dfs will fail 

void dfs(vector<int>list[], vector<int>&visited, vector<int> &distance, int i)
{
    visited[i]=1;
    for(auto x:list[i])
    {
        if(!visited[x])
        {
            distance[x]=1+distance[i];
            dfs(list,visited,distance, x);
        }
    }
}

void shortedDistance(vector<int>list[],int vertices, vector<int> &distance)
{
    vector<int>visited(vertices+1,0);
    for(int i=1;i<=vertices;i++)
    {
        if(!visited[i])
        {
            dfs(list, visited, distance, i);
        }
    }
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
    vector<int> distance(vertices+1, 0);
    shortedDistance(list,vertices, distance);
    for(int i=1;i<=vertices;i++)
    {
        cout<<i<<"->"<<distance[i]<<" ";
    }
    return 0;
}