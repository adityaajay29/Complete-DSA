#include <iostream>
#include <vector>
using namespace std;

// concept: there are 2 types of edges, forward edge and back edge
// forward edge is the edge btwn node and its parent
// back edge is edge between node and its anecestor
// backedge can never be a bridge 

// appoach: 
// we will use intime of all nodes
// we will also use lowest ancestor for all nodes 
// we find the lowest anceststor of a node by finding its adjecent which is not its parent 
// and making its lowest as min of its low and intime of that adjecent node
// if low of a node is less than its parent, then it can't be a bridge bcoz
// there is an ancestor connected to it
// in the dfs call , there are 3 cases
// 1. if adj is parent, dont do any thing
// 2. if adj is visited, and not parent, then it must be ancestor, make its low as min(low[node],in[adj])
// 3. else, call dfs for that adj
// after returning, for each node, if adjecent's low is more than its caller parent's inTime, 
// it means it has no ancestor, so it is a bridge
// also, if child has ancestor, then its parent must be that node as ancestor, so make low of parent as 
// min(low[child],low[parent])
// TC:O(v+e)
// SC:O(v+e)+O(2v)

int timer=0;

void dfs(vector<int>list[],vector<int>&visited,vector<int>&inTime,vector<int>&low,int i,int parent)
{
    // initially both in and low are same as timer
    visited[i]=1;
    inTime[i]=timer;
    low[i]=timer++;
    for(auto x:list[i])
    {
        // if visited and parent, continue
        if(x==parent)
        continue;
        // if visited and not parent
        // it is ancestor, so update the low 
        if(visited[x])
        {
            low[i]=min(low[i],inTime[x]);
        }
        // if not visited, call dfs for adjs
        else
        {
            dfs(list,visited,inTime,low,x,i); 
            // if x has ancestor say node1, then its parent also must have node1 as ancsestor
            // update the parent's low acc to ancestor
            low[i]= min(low[i], low[x]);
            // if low of child/adj is more than inTime of its parent/caller, it means it has no ancestor connected to it
            // it means its a bridge
            if(low[x]>inTime[i])
            cout<<i<<"-"<<x<<" is a bridge"<<endl;
        }
    }
}

void bridges(vector<int>list[],int &vertices,vector<int>&visited,vector<int>&inTime,vector<int>&low)
{
    for(int i=1;i<=vertices;i++)
    {
        if(!visited[i])
        {
            // initialise parent as -1
            dfs(list,visited,inTime,low,i,-1);
        }
    }
}

int main()
{
    int vertices,edges,u,v;
    cin>>vertices>>edges;
    vector<int>visited(vertices+1,0);
    vector<int>inTime(vertices+1,INT_MAX);
    vector<int>low(vertices+1,INT_MAX);
    vector<int>list[vertices+1];
    while(edges--)
    {
        cin>>u>>v;
        list[u].push_back(v);
        list[v].push_back(u);
    }
    bridges(list,vertices,visited,inTime,low);
    for(int i=1;i<inTime.size();i++)
    cout<<inTime[i]<<" ";
    cout<<endl;
    for(int i=1;i<low.size();i++)
    cout<<low[i]<<" ";
    cout<<endl;
    return 0;
}