#include <iostream>
#include <vector>
using namespace std;

bool detectCycle(vector<int>list[],vector<int>&visited,vector<int>&dfsVisited,int i)
{
    visited[i]=1;
    dfsVisited[i]=1;
    for(auto x:list[i])
    {
        if(!visited[x])
        {
            // return true value to the caller if cycle detected
            if(detectCycle(list,visited,dfsVisited,x))
            return true;
        }
            // cycle will be detected only when that node is marked visited 
            // in both visited and dfsvisited arrays
        else if(dfsVisited[x])
        return true;
    }
    // loop cpmletes for curr i, no more adjecent left for that vertex
    // if the call for the node is over, mark this node as unvisited in the dfsVisited array 
    // call for that vertex in current dfs is over
    // return control back to the caller
    dfsVisited[i]=0;
    return false;
}

bool components(vector<int>list[],int vertices)
{
    // creating 2 vectors for marking as visited
    // mark visited, if once the node is visited
    vector<int>visited(vertices+1,0);
    // mark as unvisited if it is not anymore in the dfs call
    vector<int>dfsVisited(vertices+1,0);
    for(int i=1;i<vertices;i++)
    {
        if(!visited[i])
        {
            if(detectCycle(list,visited,dfsVisited,i))
            return true;
        }
    }
    return false;
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
    vector<int>list[vertices+1];
    for(int i=0;i<edges;i++)
    {
        cout<<"enter directed connection ";
        cin>>u>>v;
        directedGraph(list,u,v);
    }
    for(int i=1;i<=vertices;i++)
    {
        for(auto x:list[i])
        cout<<i<<"->"<<x<<" ";
        cout<<endl;
    }
    cout<<components(list,vertices)<<endl;
    return 0;
}