// shortest path in undirected weighted graph
// uses bfs
// uese minHeap
// so time compl. is O(v+e)*O(logv) ~ O(vlogv)
// using priority queue to store wt and node,as min distance is needed

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> dijkstrasAlgo(vector<pair<int,int> >list[],int vertices,int source)
{
    // creating a minheap of dist,node
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >pq;
    // initial dist of all is infinite
    vector<int>distance(vertices+1,INT_MAX);
    // marking distance of src from src as 0
    distance[source]=0;
    // push src in pq
    pq.push({distance[source],source});
    while(!pq.empty())
    {
        int distPrev=pq.top().first;
        int nodePrev=pq.top().second;
        pq.pop();
        for(auto x:list[nodePrev])
        {
            // x.first is node
            // x.second is its wt
            if(distance[x.first]>distPrev+x.second)
            {
                distance[x.first]=distPrev+x.second;
                // push the new lesser distance of that node and that node to the minHeap
                pq.push({distance[x.first],x.first});
            }
        }
    }
    return distance;
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
    vector<pair<int,int> >list[vertices+1];
    for(int i=0;i<edges;i++)
    {
        cout<<"enter connection with weight ";
        cin>>u>>v>>wt;
        undirectedWtdgraph(list,u,v,wt);
    }
    for(int i=1;i<=vertices;i++)
    {
        for(auto x:list[i])
        cout<<i<<"->"<<x.first<<","<<x.second<<" ";
        cout<<endl;
    }
    vector<int>minDistance=dijkstrasAlgo(list,vertices,1);
    cout<<"the minimum distance of source with all vertex is"<<endl;
    for(int i=1;i<minDistance.size();i++)
    {
        cout<<minDistance[i]<<" ";
    }
    cout<<endl;
    return 0;
}

