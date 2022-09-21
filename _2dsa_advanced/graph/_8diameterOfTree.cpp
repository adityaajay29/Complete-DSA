#include <iostream>
#include <vector>
using namespace std;

int maxDistance;
int maxNode;

// approach:
// use dfs twice;
// first, find the max distance of any node from any given node, say node 1
// let the node found at max distance from node 1 be node x
// again, call dfs to find the node at max dist from node x
// that will be the max diameter of the tree
// time(2*O(v+e))
// space :O(n)

void dfs(vector<int>list[],vector<int>&visited,int node,int distance)
{
    visited[node]=1;
    // if we get a node at greater distance, then only that node will be assigned as maxNode
    if(distance>maxDistance)
    {
        maxDistance=distance;
        maxNode=node;
    }
    for(auto x:list[node])
    {
        if(!visited[x])
        dfs(list,visited,x,distance+1);
    }
}

int main()
{
    int vertices;
    cin>>vertices;
    vector<int>list[vertices+1];
    for(int i=0;i<vertices-1;i++)
    {
        int u,v;
        cin>>u>>v;
        list[u].push_back(v);
        list[v].push_back(u);
    }
    vector<int>visited(vertices+1,0);
    // initially maxDiam=-1
    maxDistance=-1;
    // call dfs for starting node with dist as 0 initially 
    dfs(list,visited,1,0);
    cout<<maxNode<<endl;
    cout<<maxDistance<<endl;
    // now we found the node x
    // again, make all unvisited
    for(int i=0;i<=visited.size();i++)
    visited[i]=0;
    // again let maxDist=-1
    maxDistance=-1;
    // again, call dfs for node x, with distance as 0 initially
    dfs(list,visited,maxNode,0);
    // now we found max diameter
    cout<<maxNode<<endl;
    cout<<maxDistance<<endl;
    return 0;
}