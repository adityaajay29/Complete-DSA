#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int shortestDist(vector<int>list[],int vertices)
{
    vector<int>visited(vertices+1,0);
    vector<int>distance(vertices+1,0);
    queue<int>q;
    if(!visited[1])
        {
            visited[1]=1;
            q.push(1);
            while(!q.empty())
            {
                int parent=q.front();
                q.pop();
                for(auto child:list[parent])
                {
                    if(!visited[child])
                    {
                        visited[child]=1;
                        distance[child]=1+distance[parent];
                        q.push(child);
                    }
                }
            }
        }
    return distance[vertices];
}

int main()
{
    int t,vertices,edges;
    cin>>t;
    while(t--)
    {
        cin>>vertices>>edges;
        vector<int>list[vertices+1];
        for(int i=0;i<edges;i++)
        {
            int u,v;
            cin>>u>>v;
            list[u].push_back(v);
            list[v].push_back(u);
        }
        cout<<shortestDist(list,vertices)<<endl;
    }
    return 0;
}