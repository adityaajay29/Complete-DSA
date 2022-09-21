#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m, x;
        cin>>n>>m;
        vector<int> arr(n);
        for(int i=0;i<n;i++)
        {
            cin>>x;
            arr[i] = x;
        }
        cout<<aggressiveCows(arr, m)<<endl;
    }
    return 0;
}