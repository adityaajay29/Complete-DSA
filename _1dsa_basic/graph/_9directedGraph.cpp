#include <iostream>
#include <vector>
using namespace std;

void directedGraph(vector<int>list[],int u,int v)
{
    list[u].push_back(v);
}

int main()
{
    int vertices,edges,u,v;
    cout<<"enter vertices ";
    cin>>vertices;
    cout<<"enter edges ";
    cin>>edges;
    vector<int>list[vertices+1];
    for(int i=0;i<edges;i++)
    {
        cout<<"enter directed connection ";
        cin>>u>>v;
        directedGraph(list,u,v);
    }
    for(int i=1;i<=vertices;i++)
    {
        for(auto x:list[i])
        cout<<i<<"->"<<x<<" ";
        cout<<endl;
    }
    return 0;
}