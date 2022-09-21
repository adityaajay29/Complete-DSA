#include <iostream>
#include <vector>
// #include <queue>
using namespace std;

// used to find MST
// implemented using disjoint set
// TC : O(nlogn) to sort, O(4*alpha) for disjoint set ->o(vlogv)
// SC: O(n)+O(n)
// aux space for recursion call stack
// using minimum pq to store min weigted set pair along with the pair

vector<int>ranked(10000);
vector<int>parent(10000);

struct mst
    {
        int u;
        int v;
        int wt;
        mst(int first,int second,int weight)
        {
            u=first;
            v=second;
            wt=weight;
        }
    };
    
static bool myComp(mst a,mst b)
{
    return a.wt<b.wt;
}

void createSets(int vertices)
{
    for(int i=1;i<=vertices;i++)
    {
        parent[i]=i;
        ranked[i]=0;
    }
}

int findParent(int givenNode)
{
    if(parent[givenNode]==givenNode)
    return givenNode;
    else 
    return parent[givenNode]=findParent(parent[givenNode]);
}

void makeUnion(int u,int v)
{
    u=findParent(u);
    v=findParent(v);
    if(ranked[u]>ranked[v])
    {
        parent[v]=u;
    }
    else if(ranked[v]>ranked[u])
    {
        parent[u]=v;
    }
    else
    {
        parent[v]=u;
        ranked[u]++;
    }
}

void kruskal(vector<mst>&list)
{
    int cost=0;
    vector<pair<int,int> >tree;
    for(auto x:list)
    {
        int p1=findParent(x.u);
        int p2=findParent(x.v);
        int weight=x.wt;
        if(p1!=p2)
        {
            cost+=weight;
            makeUnion(x.u,x.v);
            tree.push_back({x.u,x.v});
        }
    }
    cout<<"the cost of mst is "<<cost<<endl;
    for(auto x:tree)
    cout<<x.first<<"->"<<x.second<<endl;
}

int main()
{
    int vertices,edges;
    cout<<"enter no of vertices and edges ";
    cin>>vertices>>edges;
    int u,v,wt;
    createSets(vertices);
    vector<mst>list;
    for(int i=0;i<edges;i++)
    {
        cin>>u>>v>>wt;
        list.push_back(mst(u,v,wt));
    }
    sort(list.begin(),list.end(),myComp);
    kruskal(list);
    return 0;
}