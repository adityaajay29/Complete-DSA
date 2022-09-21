#include <iostream>
#include <vector>
using namespace std;

// approach:
// call dfs, when adjecents of a node are completed, make the size of that node as sbutree as size 1
// and return 1 to its parent node
// the size of the parent will be incremented as per size returned by its child, 
// i.e., currSize+=dfs(child)

int dfs(vector<int>list[],vector<int>&visited,vector<int>&size,int i)
{
    visited[i]=1;
    int currSize=1;
    for(auto x:list[i])
    {
        if(!visited[x])
        {
            currSize+=dfs(list,visited,size,x);
        }
    }
    size[i]=currSize;
    return currSize;
}

vector<int> subtreeSize(vector<int>list[],int vertices)
{
    vector<int>visited(vertices+1,0);
    vector<int>size(vertices+1,0);
    for(int i=1;i<=vertices;i++)
    {
        if(!visited[i])
        {
            dfs(list,visited,size,i);
        }
    }
    return size;
}

void graph(vector<int>list[],int u,int v)
{
    list[u].push_back(v);
    list[v].push_back(u);
}

int main()
{
    int vertices;
    cin>>vertices;
    vector<int>list[vertices+1];
    for(int i=0;i<vertices-1;i++)
    {
        int u,v;
        cin>>u>>v;
        graph(list,u,v);
    }
    vector<int>ans=subtreeSize(list,vertices);
    for(auto x:ans)
    cout<<x<<" ";
    return 0;
}