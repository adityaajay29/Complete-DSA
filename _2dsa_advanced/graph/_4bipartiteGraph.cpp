#include <iostream>
#include <vector>
using namespace std;

// example: interactions only with opposite gender 

bool dfs(vector<int>list[],vector<int>&colored,int i)
{
    for(auto x:list[i])
    {
        if(colored[x]==-1)
        {
            colored[x]=1-colored[i];
            if(dfs(list,colored,x)==false)
            return false;
        }
        else if(colored[x]==colored[i])
        return false;
    }
    return true;
}

bool isBipartite(vector<int>list[],int vertices)
{
    vector<int>colored(vertices+1,-1);
    for(int i=1;i<=vertices;i++)
    {
        if(colored[i]==-1)
        {
            colored[i]=0;
            if(dfs(list,colored,i)==false)
            return false;
        }
    }
    return true;
}

void graph(vector<int>list[],int u,int v)
{
    list[v].push_back(u);
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
    cout<<"is the graph bipartite"<<endl;
    cout<<isBipartite(list,vertices)<<endl;
    return 0;
}