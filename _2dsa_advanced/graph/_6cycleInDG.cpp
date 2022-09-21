#include <iostream>
#include <vector>
using namespace std;

bool dfs(vector<int>list[],vector<int>&visited,int i)
{
    // mark the curr node as active in dfs
    visited[i]=1;
    for(auto x:list[i])
    {
        if(!visited[x])
        {
            if(dfs(list,visited,x))
            return true;
        }
        // if the adje is visited and is in dfs call, means there is a backedge, hence cycle
        else if(visited[x]==1)
        return true;
    }
    // all adjectents completed, so mark the curr node as out of the dfs call
    // for marking it out of dfs, we make it marked 2 in the visited array 
    visited[i] = 2;
    return false;
}

bool cycleCheck(vector<int>list[],int vertices)
{
    // status of visited is :
    // 0 for unvisited
    // 1 if it is in current dfs call
    // 2 if dfs call for all the adjecents of that node is completed
    vector<int>visited(vertices+1,0);
    for(int i=1;i<=vertices;i++)
    {
        if(!visited[i])
        {
            if(dfs(list,visited,i))
            return true;
        }
    }
    return false;
}

void graph(vector<int>list[],int u,int v)
{
    list[u].push_back(v);
}

int main()
{
    int vertices;
    int edges;
    cout<<"enter no of vertices and edges"<<endl;
    cin>>vertices>>edges;
    vector<int>list[vertices+1];
    for(int i=0;i<edges;i++)
    {
        int u,v;
        cout<<"enter connections ";
        cin>>u>>v;
        graph(list,u,v);
    }
    cout<<"is cycle present?"<<endl;
    cout<<(cycleCheck(list,vertices) ? "yes" : "no")<<endl;
    return 0;
}