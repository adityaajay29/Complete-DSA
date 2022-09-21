#include <iostream>
#include <vector>
using namespace std;

void primsBrute(vector<pair<int,int> >list[],int vertices)
{
    vector<int>key(vertices,INT_MAX);
    vector<int>MST(vertices,0);
    vector<int>parent(vertices,-1);
    key[0]=0;
    parent[0]=-1;
    // iterating for vertices-1 edges
    for(int i=0;i<vertices-1;i++)
    {
        int min=INT_MAX;
        int prev;
        // finding node with min key value
        for(int node=0;node<vertices;node++)
        {
            if(MST[node]==0 && key[node]<min)
            // making min as this node key
             min=key[node];
             prev=node;
             // marking that node mst as 1
             MST[node]=1;
            for(auto x:list[prev])
            {
                if(MST[x.first]==0 && x.second<key[x.first])
                key[x.first]=x.second;
                parent[x.first]=prev;
            }
        }
    }
    for(int i=1;i<parent.size();i++)
    {
        cout<<parent[i]<<"->"<<i<<endl;
    }
}

void undirectedWtdgraph(vector<pair<int,int> >list[],int u,int v,int wt)
{
    list[u].push_back({v,wt});
    list[v].push_back({u,wt});
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
        undirectedWtdgraph(list,u,v,wt);
    }
    for(int i=0;i<vertices;i++)
    {
        for(auto x:list[i])
        cout<<i<<"->"<<x.first<<","<<x.second<<" ";
        cout<<endl;
    }
    primsBrute(list,vertices);
    return 0;
}