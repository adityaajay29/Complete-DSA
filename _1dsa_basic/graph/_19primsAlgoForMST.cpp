#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// using min priority queue, so that the node having min keyVal val is always on the top
// time comp - O((v+e)*log(v))

vector<int> primsAlgo(vector<pair<int,int> >list[],int vertices,int source)
{
    // marking all keyVals as infinite initially 
    vector<int>keyVal(vertices,INT_MAX);
    // mst not involved initially
    vector<int>mst(vertices,0);
    // initial parent as -1
    vector<int>parent(vertices,-1);
    // making keyVal of src as 0
    keyVal[source] = 0;
    parent[source] = -1;
    // creating a minimum priority queue to store prev and its keyVal
    // it is used to get the min value of keyVal
    // pq<{keyVal,prev}>
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >pq;
    pq.push({keyVal[source],source});
    // traversing for v-1 edges is not correct in prim's algo
    // for(int i=0;i<vertices-1;i++)
    while(!pq.empty())
    {
        // now, the prev having keyVal with min value is on top of pq
        int prev=pq.top().second;
        pq.pop();
        mst[prev]=1;
        for(auto x:list[prev])
        {
            // if adj is not in mst and its wt is less than its keyVal val, make the wt as its keyVal val
            if(!mst[x.first] && keyVal[x.first]>x.second)
            {
                keyVal[x.first]=x.second;
                // pusing that prev in pq
                // pq contains keyVal and the node
                pq.push({keyVal[x.first],x.first});
                // making prev as its parent
                parent[x.first]=prev;
            }
        }
    }
    return parent;
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
    int source=0;
    vector<int>ans=primsAlgo(list,vertices,source);
    cout<<"the min spanning tree is"<<endl;
    for(int i=1;i<vertices;i++)
    {
        cout<<"parent of "<<i<<" is "<<ans[i]<<endl;
    }
    return 0;
}