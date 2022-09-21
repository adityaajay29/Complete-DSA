#include <iostream>
#include <vector>
using namespace std;

// conclusions:
// 1. vertices of a bridge will be cut vertex or articulation point only when it's degree>1
// 2. articulation point doesn't need to be vertices of bridge
// 3. finding bridge algo can't be used to find articulation points
// 4. we use concept of dfs tree to find the cut vertices

// for every node, we will look if its subtree will get disconnected if that node is removed
// for that, we will se if its adjecent is connected with any of its ancestor or not, i.e., 
// if(low[x]>=in[i]), that is there is no ancestor of i connected to x, then i is an articulation point
// we also keep track of no. of subtrees of a given node
// we consider the case of begining node seperately, because if be use this concept for main node, 
// then main node will always come out to be the cut vertex, which is not true,
// if there is only 1 subtree of main node, as in this case, the graph will still be connected

vector<int>visited(100001,0);
vector<int>in(100001,INT_MAX);
vector<int>low(100001,INT_MAX);
int timer;
int children;

void dfs(vector<int>list[],int i,int parent)
{
    visited[i]=1;
    in[i]=low[i]=timer++;
    for(auto x:list[i])
    {
        if(x==parent)
        continue;
        else if(visited[x])
        {
            low[i]=min(low[i],in[x]);
        }
        else 
        {
            dfs(list,x,i);
            low[i]=min(low[i],low[x]);
            // if node has no backedge,then node is ap, (not x)
            if(in[i]<=low[x] && parent!=-1)
            cout<<i<<" is articulation point"<<endl;
            children++;
        }
    }
    // if multiple child of root node, then it is a ap
    if(parent==-1 && children>1)
    cout<<i<<" is articulation point"<<endl;
}

void articulationPoints(vector<int>list[],int vertices)
{
    for(int i=0;i<vertices;i++)
    {
        if(!visited[i])
        dfs(list,i,-1);
    }
}

int main()
{
    int vertices,edges;
    cin>>vertices>>edges;
    vector<int>list[vertices+1];
    while(edges--)
    {
        int u,v;
        cin>>u>>v;
        list[u].push_back(v);
        list[v].push_back(u);
    }
    articulationPoints(list,vertices);
    return 0; 
}