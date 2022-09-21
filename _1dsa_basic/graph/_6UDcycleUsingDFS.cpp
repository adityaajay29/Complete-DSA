#include <iostream>
#include <vector>
using namespace std;

bool cycleCheck(vector<int>list[],vector<int>&visited,int i,int parent)
{
    visited[i]=1;
    for(auto x:list[i])
    {
        if(!visited[x])
        {
            // if condition to return the true value to its caller,if true exists
            // making the parent node as the parent of current node
            if(cycleCheck(list,visited,x,i))
            return true;
        }
        // if the node is already visited and it is not parent, it means there is a cycle
        // some other node visited that node
        else if(x!=parent)
        return true;
    }
    return false;
}

bool componentsCheck(vector<int>list[],int vertices)
{
    vector<int>visited(vertices+1,0);
    for(int i=1;i<=vertices;i++)
    {
        if(!visited[i])
        {
            // initialising parent as -1
            if(cycleCheck(list,visited,i,-1))
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
    cout<<componentsCheck(list,vertices)<<endl;
    return 0;
}