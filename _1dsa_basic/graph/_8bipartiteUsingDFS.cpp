#include <iostream>
#include <vector>
using namespace std;

bool checkBipartite(vector<int>list[],vector<int>&color,int i)
{
    for(auto x:list[i])
    {
        if(color[x]==-1)
        {
            color[x]=1-color[i];
            if(!checkBipartite(list,color,x))
            return false;
        }
        else if(color[x]==color[i])
        return false;
    } 
    return true;
}

bool componentsCheck(vector<int>list[],int vertices)
{
    vector<int>color(vertices+1,-1);
    for(int i=1;i<=vertices;i++)
    {
        if(color[i]==-1)
        {
            color[i]=0;
            if(!checkBipartite(list,color,i))
            return false;
        }
    }
    return true;
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