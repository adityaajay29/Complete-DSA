#include <iostream>
#include <vector>
using namespace std;

// array named list of type vector
// vertically its array, horizontally its vector

// O(v+e) memory, instead ofO(v*v) in matrix representation
// creating a non-directive graph

void createGraph(vector<int>list[],int u,int v)
{
    // since it is a non directive graph, we have to create edges for both the vertices
    // creating edge between (u,v)
    list[u].push_back(v);
    // creating edge between (v,u)
    list[v].push_back(u);
}

// in general, we will be given number of vertices and number of edges
// so, for each edges, we will ask user for the connections (u,v)

int main()
{
    int vertices,edges;
    int u,v;
    cout<<"enter number of vertices ";
    cin>>vertices;
    cout<<"enter number of edges ";
    cin>>edges;
    vector<int>list[vertices];
    for(int i=0;i<edges;i++)
    {
        cout<<"enter connection ";
        cin>>u>>v;
        createGraph(list,u,v);
    }   
    cout<<"the graph is"<<endl;
    for(int i=0;i<vertices;i++)
    {
        for(auto x:list[i])
        cout<<i<<"->"<<x<<" ";
        cout<<endl;
    }
    return 0;
}
