// similar to bfs
// used for topo sort
// the approach is, to start from the node with 0 indegre
// then from low to high indegree,
// also , if one node finished, with indegree>0,reduce its indegree, so that there is no more dependency
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> kahnsAlgo(vector<int>list[],int vertices)
{
    vector<int>indegree(vertices,0);
    vector<int>topoSort;
    queue<int>q;
    // running a loop to get the indegree of every vertex
    for(int i=0;i<vertices;i++)
    {
        for(auto x:list[i])
        indegree[x]++;
    }
    // push all the nodes with 0 indegree in the queue
    for(int i=0;i<vertices;i++)
    {
        if(indegree[i]==0)
        q.push(i);
    }
    while(!q.empty())
    {
        int temp=q.front();
        topoSort.push_back(temp);
        q.pop();
        for(auto x:list[temp])
        {
            // if indegree of adjecent is not 0, reduce it by 1
            indegree[x]--;
            if(indegree[x]==0)
            q.push(x);
        }
    }
    return topoSort;
}

void directedGraph(vector<int>list[],int u,int v)
{
    list[u].push_back(v);
}

int main()
{
    int vertices,edges,u,v;
    cout<<"enter vertices ";
    cin>>vertices;
    cout<<"enter edges ";
    cin>>edges;
    vector<int>list[vertices];
    for(int i=0;i<edges;i++)
    {
        cout<<"enter directed connection ";
        cin>>u>>v;
        directedGraph(list,u,v);
    }
    for(int i=0;i<vertices;i++)
    {
        for(auto x:list[i])
        cout<<i<<"->"<<x<<" ";
        cout<<endl;
    }
    vector<int>ans=kahnsAlgo(list,vertices);
    for(int i=0;i<ans.size();i++)
    cout<<ans[i]<<" ";
    return 0;  
} 