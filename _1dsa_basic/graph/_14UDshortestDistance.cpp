#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// using bfs

// int shortestDistance(vector<int>list[],int vertices,int source,int target)
// {
//     // initially marking the distance of all nodes from src as infinity
//     vector<int>distance(vertices,INT_MAX);
//     queue<int>q;
//     q.push(source);
//     // dist of src to src is 0
//     distance[source]=0;
//     while(!q.empty())
//     {
//         int temp=q.front();
//         q.pop();
//         for(auto x:list[temp])
//         {
//             // if distance btw src and node is more, make it less, and put it in queue
//             if(distance[x]>distance[temp]+1)
//             {
//                 distance[x]=distance[temp]+1;
//                 // if the distacnce is already less, then no need to push the node in queue
//                 q.push(x);
//             }
//         }
//     }
//     // return the min distance
//     return distance[target];
// }

vector<int> shortestDistance(vector<int>list[],int vertices,int source)
{
    queue<int>q;
    vector<int>distance(vertices+1,INT_MAX);
    q.push(source);
    distance[source]=0;
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        for(auto x:list[node])
        {
            if(distance[x]>distance[node]+1)
            {
                distance[x]=distance[node]+1;
                q.push(x);
            }
        }
    }
    return distance;
}

void undirectedGraph(vector<int>list[],int u,int v)
{
    list[u].push_back(v);
    list[v].push_back(u);
}

int main()
{
    int vertices;
    int edges;
    int u,v;
    cout<<"enter vertices ";
    cin>>vertices;
    cout<<"enter edges ";
    cin>>edges;
    vector<int>list[vertices+1];
    for(int i=0;i<edges;i++)
    {
        cout<<"enter connection ";
        cin>>u>>v;
        undirectedGraph(list,u,v);
    }
    for(int i=1;i<=vertices;i++)
    {
        for(auto x:list[i])
        cout<<i<<"->"<<x<<" ";
        cout<<endl;
    }
    int source=1;
    // int target=8;
    cout<<"the minimum distance between source and target is ";
    vector<int>ans=shortestDistance(list,vertices,source);
    for(int i=1;i<=vertices;i++)
    cout<<ans[i]<<" ";
    cout<<endl;
    return 0;
}