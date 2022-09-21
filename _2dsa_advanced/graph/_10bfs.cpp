#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> bfsTrav(vector<int>list[],int vertices)
{
    vector<int>visited(vertices+1,0);
    vector<int>bfs;
    vector<int>dist(vertices+1,0);
    queue<int>q;
    for(int i=1;i<=vertices;i++)
    {
        if(!visited[i])
        {
            visited[i]=1;
            q.push(i);
            while(!q.empty())
            {
                int parent=q.front();
                q.pop();
                bfs.push_back(parent);
                for(auto child:list[parent])
                {
                    if(!visited[child])
                    {
                        visited[child]=1;
                        // incrementing the distance by one for the child, wrt parent
                        dist[child]=1+dist[parent];
                        q.push(child);
                    }
                }
            }
        }
    }
    return dist;
}

int main()
{
    int vertices;
    int edges;
    vector<int>list[vertices+1];
    cin>>vertices>>edges;
    for(int i=0;i<edges;i++)
    {
        int u,v;
        cin>>u>>v;
        list[u].push_back(v);
        list[v].push_back(u);
    }
    vector<int> ans=bfsTrav(list,vertices);
    for(int i=1;i<=vertices;i++)
    {
        cout<<i<<"->"<<ans[i]<<" ";
    }
    return 0;
}