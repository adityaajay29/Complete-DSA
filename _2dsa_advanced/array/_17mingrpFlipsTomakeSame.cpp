#include <iostream>
#include <vector>
using namespace std;

void minGrpFlips(vector<int>v,int n)
{
    int i;
    for(i=1;i<n;i++)
    {
        if(v[i]!=v[i-1])
        {
            if(v[i]!=v[0])
            cout<<"from "<<i<<" to ";
            else
            cout<<i-1<<endl;
        }
    }
    if(v[n-1]!=v[0])
    cout<<n-1<<endl;
}

int main()
{
    vector<int>v{1,1,0,0,0,1,1,1,0,0};
    int n=v.size();
    minGrpFlips(v,n);
    return 0;
}