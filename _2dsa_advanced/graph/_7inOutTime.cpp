#include <iostream>
#include <vector>
using namespace std;

int timer=1;

void dfs(vector<int>list[],vector<int>&visited,vector<int>&inTime,vector<int>&outTime,int i)
{
    
    visited[i]=1;
    inTime[i]=timer++;
    for(auto x:list[i])
    {
        if(!visited[x])
        {
            dfs(list,visited,inTime,outTime,x);
        }
    }
    outTime[i]=timer++;
}

void inOutTime(vector<int>list[],vector<int>&inTime,vector<int>&outTime,int vertices)
{
    vector<int>visited(vertices+1,0);
    for(int i=1;i<=vertices;i++)
    {
        if(!visited[i])
        {
            dfs(list,visited,inTime,outTime,i);
        }
    }
}

bool nodeLiesInSubtreeOfOther(int node1,int node2,vector<int>&inTime,vector<int>&outTime)
{
    return (inTime[node1]<inTime[node2] && outTime[node1]>outTime[node2]
        || inTime[node1]>inTime[node2] && outTime[node1]<outTime[node2]);
}

int main()
{
    int vertices;
    int edges;
    cin>>vertices>>edges;
    vector<int>list[vertices+1];
    vector<int>inTime(vertices+1,-1);
    vector<int>outTime(vertices+1,-1);
    for(int i=0;i<edges;i++)
    {
        int u,v;
        cin>>u>>v;
        list[u].push_back(v);
        list[v].push_back(u);
    }
    inOutTime(list, inTime, outTime, vertices);
    for(int i=1;i<inTime.size();i++)
    cout<<inTime[i]<<" ";
    cout<<endl;
    for(int i=1;i<outTime.size();i++)
    cout<<outTime[i]<<" ";
    cout<<endl;
    int node1;
    int node2;
    cin>>node1>>node2;
    cout<<nodeLiesInSubtreeOfOther(node1, node2, inTime, outTime)<<endl;
    return 0;
}
