#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// conditions for topo sort:
// the graph should be DAG: directed, acycllic graph 
// we use indegree array 

vector<int> topoSort(vector<int>list[],int vertices)
{
    vector<int>inDegree(vertices+1,0);
    vector<int>topo;
    for(int i=0;i<vertices;i++)
    {
        for(auto x:list[i])
        inDegree[x]++;
    }
    queue<int>q;
    for(int i=1;i<=vertices;i++)
    {
        if(inDegree[i]==0)
        q.push(i);
    }
    while(!q.empty())
    {
        int curr=q.front();
        q.pop();
        topo.push_back(curr);
        for(auto x:list[curr])
        {
            inDegree[x]--;
            if(inDegree[x]==0)
            q.push(x);
        }
    }
    return topo;
}

int main()
{
    int vertices,edges,u,v;
    cin>>vertices>>edges;
    vector<int>list[vertices+1];
    while(edges--)
    {
        cin>>u>>v;
        list[u].push_back(v);
    }
    vector<int>ans=topoSort(list,vertices);
    for(auto x:ans)
    cout<<x<<" ";
    return 0;
}