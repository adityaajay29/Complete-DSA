#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int bfs(vector<int>list[],int &vertices,int &node)
{
    vector<int>visited(vertices+1,0);
    queue<int>q;
    vector<int>dist(vertices+1,0);
    visited[node]=1;
    q.push(node);
    while(!q.empty())
    {
        int parent=q.front();
        q.pop();
        for(auto child:list[parent])
        {
            if(!visited[child])
            {
                visited[child]=1;
                dist[child]=1+dist[parent];
                q.push(child);
            }
        }
    }
    int ans=0;
    for(auto x:dist)
    {
        if(x==3)
        ans++;
    }
    return ans;
}

int main()
{
    int vertices,edges,u,v,node;
    vector<int>list[vertices+1];
    cin>>vertices>>edges;
    cin>>node;
    for(int i=0;i<edges;i++)
    {
        cin>>u>>v;
        list[u].push_back(v);
        list[v].push_back(u);
    }    
    cout<<bfs(list,vertices,node)<<endl;
    return 0;
}
