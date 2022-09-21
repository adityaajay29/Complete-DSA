#include <iostream>
#include <vector>
using namespace std;

int cCount; 

void dfs(vector<int>list[],vector<int>&visited,int i)
{
    visited[i]=1;
    cCount++;
    for(auto x:list[i])
    {
        if(!visited[x])
        dfs(list,visited,x);
    }
}


void countRoutes(vector<int>list[],int vertices,int &exits,long long &captains)
{
    vector<int>visited(vertices+1,0);
    for(int i=1;i<=vertices;i++)
    {
        if(!visited[i])
        {
            exits++;
            cCount=0;
            dfs(list,visited,i);
            captains=(captains*cCount)%1000000007;
        }
    }
}

int main() {
	// your code goes here
	int t;
    cin>>t;
    int vertices;
    int edges;
    int u,v;
    while(t--)
    {
        cin>>vertices>>edges;
        vector<int>list[vertices+1];
        for(int i=0;i<edges;i++)
        {
            cin>>u>>v;
            list[u].push_back(v);
            list[v].push_back(u);
        }
        int exits=0;
        long long captains=1;
        countRoutes(list,vertices,exits,captains);
        cout<<exits<<" "<<captains<<endl;
    }
    return 0;
}