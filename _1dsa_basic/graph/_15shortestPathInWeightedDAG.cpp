#include <iostream>
#include <vector>
#include <stack>
using namespace std;
// using topoSort with dfs

void TopoSort(vector<pair<int,int> >list[],vector<int>&visited,stack<int>&s,int i)
{
    visited[i]=1;
    for(auto x:list[i])
    {
        if(!visited[x.first])
        TopoSort(list,visited,s,x.first);
    }
    s.push(i);
}

vector<int> shortestPathWDAG(vector<pair<int,int> >list[],int vertices,int source)
{
    vector<int>visited(vertices,0);
    vector<int>distance(vertices,INT_MAX);
    stack<int>s;
    for(int i=0;i<vertices;i++)
    {
        if(!visited[i])
        TopoSort(list,visited,s,i);
    }
    distance[source]=0;
    while(!s.empty())
    {
        int temp=s.top();
        s.pop();
        // if the temp is already visited
        if(distance[temp]!=INT_MAX)
        {
            for(auto x:list[temp])
            {
                if(distance[x.first]>distance[temp]+x.second)
                distance[x.first]=distance[temp]+x.second;
            }
        }
    }
    return distance;
}

void WeightedDAG(vector<pair<int,int> >list[],int u,int v,int wt)
{
    list[u].push_back({v,wt});
}

int main()
{
    int vertices,edges;
    int u,v,wt;
    cout<<"enter vertices ";
    cin>>vertices;
    cout<<"enter edges ";
    cin>>edges;
    vector<pair<int,int> >list[vertices];
    for(int i=0;i<edges;i++)
    {
        cout<<"enter connection with weight ";
        cin>>u>>v>>wt;
        WeightedDAG(list,u,v,wt);
    }
    for(int i=0;i<vertices;i++)
    {
        for(auto x:list[i])
        cout<<i<<"->"<<x.first<<","<<x.second<<" ";
        cout<<endl;
    }
    // int source=0;
    // int target=3;
    cout<<"the shortest distance between source and target in this WDAG is ";
    vector<int>ans=shortestPathWDAG(list,vertices,0);
    for(int i=0;i<vertices;i++)
    cout<<ans[i]<<" ";
    return 0;
}