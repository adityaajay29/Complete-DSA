#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// O(v+e), same as bfs

bool checkCycle(vector<int>list[],vector<int>&visited,int i)
{
    queue<pair<int,int> >q;
    visited[i]=1;
    // consider initial parent as -1
    q.push({i,-1});
    while(!q.empty())
    {
        int ver=q.front().first;
        int parent=q.front().second;
        q.pop();
        for(auto x:list[ver])
        {
            if(!visited[x])
            {
                visited[x]=1;
                q.push({x,ver});
            }
            // if the adjecent vertex is visited, and it is not the parent of node
            // it means some other vertex has visited it
            // hence, there is a cycle
            // so we will immediately return true
            else if(x!=parent)
            return true;
        }
    }
    return false;
}

bool componetsCycleCheck(vector<int>list[],int vertices)
{
    vector<int>visited(vertices+1,0);
    for(int i=1;i<=vertices;i++)
    {
        if(!visited[i])
        {
            if(checkCycle(list,visited,i))
            return true;
        }
    }
    return false;
}

void graph(vector<int>list[],int u,int v)
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
        graph(list,u,v);
    }
    for(int i=1;i<=vertices;i++)
    {
        for(auto x:list[i])
        cout<<i<<"->"<<x<<" ";
        cout<<endl;
    }
    cout<<componetsCycleCheck(list,vertices)<<endl;
    return 0;
}