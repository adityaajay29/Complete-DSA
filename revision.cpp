#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<set>
#include<limits>
#include<map>
#include<queue>
using namespace std;
typedef long long int ll;

vector<int>v[100001];
ll val[100001];
ll sum[100001];

bool visited[100001]{};
bool vis[100001]{};

int nodesum(ll root,bool *visited)
{
    ll temp=val[root];
    visited[root]=true;
    for(ll j=0;j<v[root].size();j++)
    {
        if(!visited[v[root][j]])
        {
            temp+=nodesum(v[root][j],visited);
        }
    }
return sum[root]=temp;
}

void dfs(ll i,bool *vis,ll k)
{
    vis[i]=true;
    ll temp=val[i];
    for(int j=0;j<v[i].size();j++)
    {
        if(!vis[v[i][j]])
        {
            dfs(v[i][j],vis,k);
            temp+=max(sum[v[i][j]],-k);
        }
    }
    sum[i]=temp;
}

int main()

{

ios_base::sync_with_stdio(false);

cin.tie(NULL);

cout.tie(NULL);

int t;

cin>>t;

while(t--)

{

 ll n,k;

 cin>>n>>k;

 for(ll i=1;i<=n;i++)

 cin>>val[i];

 for(ll i=0;i<=n;i++)

 {

  v[i].clear();

 }

 for(ll i=1;i<n;i++)

 {

  ll a,b;

  cin>>a>>b;

  v[a].push_back(b);

  v[b].push_back(a);

 }

//  vector<bool> visited(n, false);

 ll ans=nodesum(1,visited);

//  vector<bool> vis(n + 1, false);

 dfs(1,vis,k);

 ans=max(sum[1],-k);

 cout<<ans<<endl;

}

}