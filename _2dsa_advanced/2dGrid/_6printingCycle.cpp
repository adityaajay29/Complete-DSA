#include <iostream>
#include <vector>
using namespace std;

vector<int>cycle;

bool dfs(vector<int>list[],vector<int>&visited,int i,int parent)
{
    visited[i]=1;
    cycle.push_back(i);
    for(auto x:list[i])
    {
        if(!visited[x])
        {
            if(dfs(list,visited,x,i))
            return true;
        }
        else if(x!=parent)
        {
            cycle.push_back(x);
            return true;
        }
    }
    // pop nodes which are not forming the cycle
    cycle.pop_back();
    return false;
}

bool printCycle(vector<int>list[],int vertices)
{
    vector<int>visited(vertices+1,0);
    for(int i=1;i<=vertices;i++)
    {
        if(!visited[i])
        {
            if(dfs(list,visited,i,-1))
            return true;
        }
    }
    return false;
}

int main()
{
    int vertices,edges;
    cin>>vertices>>edges;
    int u,v;
    vector<int>list[vertices+1];
    while(edges--)
    {
        cin>>u>>v;
        list[u].push_back(v);
        list[v].push_back(u);
    }
    printCycle(list,vertices);
    int n=cycle.size();
    for(auto x:cycle)
    cout<<x<<" ";
    cout<<endl;
    return 0;
}