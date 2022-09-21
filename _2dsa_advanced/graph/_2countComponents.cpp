#include <iostream>
#include <vector>
using namespace std;

void dfsTrav(vector<int>list[],vector<int>&visited,int i)
{
    visited[i]=1;
    for(auto x:list[i])
    {
        if(!visited[x])
        {
            dfsTrav(list,visited,x);
        }
    }
}

int countComponents(vector<int>list[],int vertices)
{
    vector<int>visited(vertices+1,0);
    int count=0;
    for(int i=1;i<=vertices;i++)
    {
        if(!visited[i])
        {
            // every time the loop is run, the count of CCs will increase
            count++;
            dfsTrav(list,visited,i);
        }
    }
    return count;
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
        cout<<"enter connections";
        cin>>u>>v;
        graph(list,u,v);
    }
    cout<<"the number of components of graph are "<<countComponents(list,vertices)<<endl;
    return 0;
}