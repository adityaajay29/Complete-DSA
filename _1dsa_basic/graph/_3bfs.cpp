// concept of breadth first search is to visit the adjecent vertices first
// then adjecents of adjecents and so on
// there can be 1 or multiple components of a single graph
// time : O(v+e)
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// applications:
// shortest path in an non-weighted graph
// web crawlers
// social network search
// peer to peer search like torrent
// algos like dijkstra's, prims
// broadcasting

void BFS(vector<int>list[],int vertices)
{
    // considering indexing from 1,so visited array is from 0 to last vertex
    // filled will be from 1to7,as indexing of vertex from 1,not 0
    // marking all the visited vertex as 0 initially, meaning they are not visited
    vector<int>visited(vertices+1,0);
    // to store the visited vertex
    vector<int>bfs;
    int totalComponents=0;
    // creating queue,same as level order traversal of trees
    queue<int>q;
    // first for loop to use bfs for all the components of the graph
    // if only 1 graph component present, then this loop will only execute once
    for(int i=1;i<=vertices;i++)
    {
        // if the vertex is not visited, them only bfs for that vertex
        if(visited[i]==0)
        {
            // increasing the count of components
            totalComponents++;
            // mark that vertex as visited
            visited[i]=1;
            // push that vertex in the queue
            q.push(i);
            // check if queue is not empty
            while(q.empty()==false)
            {
                // push that vertex in bfs array, and pop from queue
                int temp=q.front();
                q.pop();
                bfs.push_back(temp);

                // traverse for all the adjecents of that vertex

                // sum of all the degrees is number of edges, or 2*edges
                // so, time compl. of this inner most loop is O(v+e)
                // e=sum(degrees)
                // v is added for worst case, when all vertexs are disconnected
                for(auto x:list[temp])
                {
                    // if that vertex is not visited, mark it as visited
                    if(visited[x]==0)
                    {
                        visited[x]=1;
                        // push that vertex in the queue
                        q.push(x);
                    }
                }
            }
        }
    }
    for(auto x:bfs)
    cout<<x<<" ";
    cout<<endl;
    cout<<"number of components of graph are "<<totalComponents<<endl;
}

void createGraph(vector<int>list[],int u,int v)
{
    list[u].push_back(v);
    list[v].push_back(u);
}

int main()
{
    int vertices,edges;
    int u,v;
    cout<<"enter number of vertices ";
    cin>>vertices;
    cout<<"enter number of edges ";
    cin>>edges;
    vector<int>list[vertices+1];
    for(int i=0;i<edges;i++)
    {
        cout<<"enter connection ";
        cin>>u>>v;
        createGraph(list,u,v);
    }   
    cout<<"the graph is"<<endl;
    for(int i=1;i<=vertices;i++)
    {
        for(auto x:list[i])
        cout<<i<<"->"<<x<<" ";
        cout<<endl;
    }
    cout<<"the BFS output is ";
    BFS(list,vertices);
    cout<<endl;
    return 0;
}