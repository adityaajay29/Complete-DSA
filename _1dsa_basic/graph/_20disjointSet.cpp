// used to detect if two given nodes belong to the same component of the graph
// idea-if two friends have the same representatives,then they are in same group

#include <iostream>
#include <vector>
using namespace std;

// creating global arrays
vector<int>parent(100001);
vector<int>ranked(100001);

// creating the sets
void createSets(int totalNodes)
{
    for(int i=1;i<=totalNodes;i++)
    {
        // initial parent as themselves, components equal to total vertices
       parent[i]=i;
        // initial rank of each is 0
       ranked[i]=0;
    }
}

// function to find the parent
int findParent(int node)
{
    if(parent[node]==node)
    return node;
    else 
    // returned value is stored as ultimate parent
    return parent[node]=findParent(parent[node]);
}

// making union 
void makeUnion(int u,int v)
{
    u=findParent(u);
    v=findParent(v);
    // if rank of u is high,make v's parent as u's parent
    if(ranked[u]>ranked[v])
    parent[v]=u;
    else if(ranked[v]>ranked[u])
    parent[u]=v;
    // if both have same rank, make any parent of other and increase the rank of parent
    else 
    {
        parent[v]=u;
        ranked[u]++;
    }
}

int main()
{
    int totalNodes,connect;
    cout<<"enter total nodes and total connections ";
    cin>>totalNodes>>connect;
    createSets(totalNodes);
    int u,v;
    while(connect--)
    {
        cout<<"enter u v ";
        cin>>u>>v;
        makeUnion(u,v);
    }
    for(int i=1;i<=totalNodes;i++)
    {
        cout<<"the parent of "<<i<<" is "<<findParent(i)<<endl;
    }
    return 0;
}