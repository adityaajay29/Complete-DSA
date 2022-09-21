#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// naive app: O(n2)
// void nextGreater(vector<int>&arr)
// {
//     int n=arr.size();
//     for(int i=0;i<n;i++)
//     {
//         int j;
//         for(int j=i+1;j<n;j++)
//         {
//             if(arr[j]>arr[i])
//             {
//                 cout<<arr[j]<<" ";
//                 break;
//             }
//         }
//         if(j==n)
//         cout<<-1<<" ";
//     }
//     // -1 for last ele
//     cout<<-1<<endl;
// }

// eff sol:
void nextGreater(vector<int>arr)
{
    int n=arr.size();
    vector<int>ans;
    stack<int>s;
    s.push(arr[n-1]);
    ans.push_back(-1);
    for(int i=n-2;i>=0;i--)
    {
        while(!s.empty() && arr[i]>s.top())
        {
            s.pop();
        }
        if(s.empty())
        ans.push_back(-1);
        else 
        ans.push_back(s.top());
        // pushing in the stack will be at last
        s.push(arr[i]);
    }
    for(auto it=ans.rbegin();it!=ans.rend();it++)
    cout<<*it<<" ";
    cout<<endl;
    // by reversing:
    reverse(ans.begin(),ans.end());
    for(auto x:ans)
    cout<<x<<" ";
}

int main()
{
    vector<int>arr{5,15,10,8,6,12,9,18};
    nextGreater(arr);
    return 0; 
}
