// using dfs
// topo sort is a sorting technique(linear ordering), in which for a connection u->v
// u should appear before v for all such u,v
// possible for DAC directed-acyclic graphs
// directed for a unique u->v
// acyclic bcoz there is no order in a cycle
// O(v+e) time
// O(v)+O(v) space, plus O(v) recursion call stack
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void topo(vector<int>list[],vector<int>&visited,stack<int>&s,int i)
{
    visited[i]=1;
    for(auto x:list[i])
    {
        if(!visited[x])
        topo(list,visited,s,x);
    }
    // when recursion call for that node ends, push that into the stack 
    // so, the last dfs for node to be called will be pushed first
    s.push(i);  
}

vector<int> components(vector<int>list[],int vertices)
{
    stack<int>s;
    vector<int>visited(vertices,0);
    for(int i=0;i<vertices;i++)
    {
        if(!visited[i])
        topo(list,visited,s,i);
    }
    vector<int>topoSort;
    while(!s.empty())
    {
       topoSort.push_back(s.top());
        s.pop();
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
    vector<int>ans=components(list,vertices);
    cout<<"the topological sorting is"<<endl;
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}