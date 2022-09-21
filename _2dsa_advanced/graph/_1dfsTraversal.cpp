#include <iostream>
#include <vector>
using namespace std;

// time : O(v+e)

void dfsTrav(vector<int>list[],vector<int>&visited,vector<int>&ans,int i)
{
    visited[i]=1;
    ans.push_back(i);
    for(auto x:list[i])
    {
        if(!visited[x])
        {
            dfsTrav(list,visited,ans,x);
        }
    }
}
vector<int>dfs(vector<int>list[],int vertices)
{
    vector<int>visited(vertices+1,0);
    vector<int>ans;
    // for loop to traverse on all the components
    for(int i=1;i<=vertices;i++)
    {
        if(!visited[i])
        dfsTrav(list,visited,ans,i);
    }
    return ans;
}

void makeGraph(vector<int>list[],int u, int v)
{
    list[u].push_back(v);
    list[v].push_back(u);
}

int main()
{
    cout<<"enter no of vertices and edges"<<endl;
    int vertices;
    int edges;
    cin>>vertices>>edges;
    vector<int>list[vertices+1];
    for(int i=0;i<edges;i++)
    {
        cout<<"enter connections"<<endl;
        int u,v;
        cin>>u>>v;
        makeGraph(list,u,v);
    }
    vector<int>ans=dfs(list,vertices);
    for(auto x:ans)
    cout<<x<<" ";
    // for(int i=1;i<=vertices;i++)
    // {
    //     for(auto x:list[i])
    //     cout<<x<<" ";
    //     cout<<endl;
    // }
    return 0;
}