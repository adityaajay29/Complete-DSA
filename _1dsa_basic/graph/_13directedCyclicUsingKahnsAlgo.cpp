#include <iostream>
#include <queue>
#include <vector>
using namespace std;

bool directedCyclicKahns(vector<int>list[],int vertices)
{
    queue<int>q;
    vector<int>indegree(vertices+1,0);
    for(int i=1;i<=vertices;i++)
    {
        for(auto x:list[i])
        indegree[x]++;
    }
    for(int i=1;i<=vertices;i++)
    {
        if(indegree[i]==0)
        q.push(i);
    }
    int topoCount=0;
    while(!q.empty())
    {
        int temp=q.front();
        q.pop();
        topoCount++;
        for(auto x:list[temp])
        {
            indegree[x]--;
            if(indegree[x]==0)
            q.push(x);
        }
    }
    // if topoSort happened, it means there was no cycle
    // hence return false
    if(topoCount==vertices)
    return false;
    return true;
}

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
    if(directedCyclicKahns(list,vertices))
    cout<<"DCG"<<endl;
    else 
    cout<<"DAG"<<endl;
    return 0;
} 