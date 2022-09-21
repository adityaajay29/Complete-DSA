#include <iostream>
#include <vector>
using namespace std;

vector<int>parent(100001);
vector<int>ranked(100001);


void makeSet(int m)
{
    for(int i=1;i<=m;i++)
    {
        parent[i]=1;
        ranked[i]=0;
    }
}

int findParent(int x)
{
    if(parent[x]==x)
    return x;
    // path compression by assigning directly the ultimate parent as the parent of any child
    return parent[x]=findParent(parent[x]);
}

void unions(int u,int v)
{
    int p1=findParent(u);
    int p2=findParent(v);
    if(ranked[u]>ranked[v])
    parent[v]=p1;
    else if(ranked[v]>ranked[u])
    parent[u]=p2;
    else 
    {
        parent[v]=p1;
        ranked[u]++;
    }
}

int main()
{
    int m,u,v;
    makeSet(m);
    cin>>m;
    while(m--)
    {
        cin>>u>>v;
        unions(u,v);
    }
}