#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// bipartite graph,if the wholegraph can be colored using only 2 colors
// with the conditionn that no 2 adjecent nodes have the same color
// if cyclic with odd vertices,then not bipartite, else bipartite
// O(v+e)

bool checkBipartite(vector<int>list[],vector<int>&colored,int i)
{
    queue<int>q;
    colored[i]=0;
    q.push(i);
    while(!q.empty())
    {
        int temp=q.front();
        q.pop();
        for(auto x:list[temp])
        {
            if(colored[x]==-1)
            {
               colored[x]=1-colored[temp];
                q.push(x);
            }
            else if(colored[x]==colored[temp])
            return false;
        }
    }
    return true;
}

bool components(vector<int>list[],int vertices)
{
    vector<int>colored(vertices+1,-1);
    for(int i=1;i<=vertices;i++)
    {
        if(colored[i]==-1)
        {
            // the moment we find that adjecent nodes are same colored, return false
            if(!checkBipartite(list,colored,i))
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
    cout<<components(list,vertices)<<endl;
    return 0;
}