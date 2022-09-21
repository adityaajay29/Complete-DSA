#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 4 direction :
// vector<int> dx{1, -1, 0, 0};
// vector<int> dy{0, 0, 1, -1};

// 8 directions : 
vector<int> dx{-1, -1, 0, 1, 1, 1, 0, -1};
vector<int> dy{0, 1, 1, 1, 0, -1, -1, -1};

bool isValid(int i, int j, int n)
{
    return (i >= 0 && i < n && j >= 0 && j < n);
}

int dijkstra(vector<vector<int> > &grid, int i, int j, int n)
{
    vector<vector<int> > distance(n, vector<int> (n, INT_MAX));
    distance[i][j] = grid[i][j];
    // pq : {distance, x, y}
    priority_queue<pair<int, pair<int,int> >, vector<pair<int, pair<int, int> > >, greater<pair<int, pair<int, int> > > > pq;
    pq.push({grid[i][j], {i, j}});
    while(!pq.empty())
    {
        int nodeDist = pq.top().first;
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        pq.pop();
        for(int k=0;k<8;k++)
        {
            if(isValid(x + dx[k], y +dy[k], n))
            {
                if(distance[x + dx[k]][y + dy[k]] > nodeDist + grid[x + dx[k]][y + dy[k]])
                {
                    distance[x + dx[k]][y + dy[k]] = nodeDist + grid[x + dx[k]][y + dy[k]];
                    pq.push({distance[x + dx[k]][y + dy[k]], {x + dx[k], y + dy[k]}});
                }
            }
        }
    }
    // for(vector<int> v : distance)
    // {
    //     for(int x : v)
    //     cout<<x<<" ";
    //     cout<<endl;
    // }
    return distance[n - 1][n - 1];
}

int main()
{
    vector<vector<int> > grid{
         {31, 100, 65, 12, 18},
         {10, 13, 47, 157, 6}, 
         {100, 113, 174, 11, 33},
         {88, 124, 41, 20, 140}, 
         {99, 32, 111, 41, 20}
        // {1, 2, 1, 1, 1},
        // {2, 1, 2, 1, 1}, 
        // {1, 2, 1, 2, 1},
        // {1, 1, 2, 1, 2}, 
        // {1, 1, 1, 2, 1}
    };
    int cost = dijkstra(grid, 0, 0, 5);
    cout<<"the min cost in going from {0, 0} to {4, 4} is "<<cost<<endl;
    return 0;
}