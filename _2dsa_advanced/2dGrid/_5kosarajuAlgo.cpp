#include <iostream>
#include <vector>
using namespace std;

// kosaraju algo for finding number of strongly connected components in directed graph
// we will use 2 dfs
// dfs1 for finding the out time of all the nodes
// dfs2, using the out time, run dfs on the transpose of the graph
// no of dfs2 calls will be the number of scc in that directed graph 

// tc : O(v+e)
// sc : O(v+e)

vector<int>outTimeNodes;
vector<int>SCC;

void dfs(vector<int>list[],vector<int>&visited,int i)
{
    visited[i]=1;
    for(auto x:list[i])
    {
        if(!visited[x])
        {
            dfs(list,visited,x);
        }
    }
    outTimeNodes.push_back(i);
}

void dfs1(vector<int>tList[],vector<int>&visited,int i)
{
    visited[i]=1;
    for(auto x:tList[i])
    {
        if(!visited[x])
        dfs1(tList,visited,x);
    }
    SCC.push_back(i);
}

void kosaraju(vector<int>list[],vector<int>tList[],int vertices)
{
    vector<int>visited(vertices+1,0);
    for(int i=1;i<=vertices;i++)
    {
        if(!visited[i])
        dfs(list,visited,i);
    }
    for(int i=0;i<=vertices;i++)
    visited[i]=0;
    for(int i=1;i<=vertices;i++)
    {
        if(!visited[outTimeNodes[vertices-i]])
        {
            // no of dfs1 calls will be the number of SCC in the graph (dac)

            dfs1(tList,visited,outTimeNodes[vertices-i]);

            cout<<"dfs1 called from node "<<outTimeNodes[vertices-i]<<" having following SCC"<<endl;
            for(auto x:SCC)
            cout<<x<<" ";
            cout<<endl;
            SCC.clear();
        }
    }
}

int main()
{
    int vertices,edges;
    cin>>vertices>>edges;
    int u,v;
    vector<int>list[vertices+1];
    vector<int>tList[vertices+1];
    while(edges--)
    {
        cin>>u>>v;
        list[u].push_back(v);
        tList[v].push_back(u);
    }
    kosaraju(list,tList,vertices);
    return 0;
}
