#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// naive app:
// void previousGeater(vector<int>&arr)
// {
//     int n=arr.size();
//     int j;
//     for(int i=0;i<n;i++)
//     {
//         for(j=i-1;j>=0;j--)
//         {
//             if(arr[j]>arr[i])
//             {
//                 cout<<arr[j]<<" ";
//                 break;
//             }   
//         }
//         // if we couldn't find a greater ele, it means j became -1
//         if(j==-1)
//         cout<<-1<<" ";
//     }
//     cout<<endl;
// }


// eff approac : O(n) time and space 
// similar to stock span problem
void previousGeater(vector<int>&arr)
{
    int n=arr.size();
    stack<int>s;
    s.push(arr[0]);
    cout<<-1<<" ";
    for(int i=1;i<n;i++)
    {
        while(!s.empty() && s.top()<=arr[i])
        {
            s.pop();
        }
        if(s.empty())
        cout<<-1<<" ";
        else
        cout<<s.top()<<" ";
        s.push(arr[i]);
    }
    cout<<endl;
}

int main()
{
    vector<int>arr{20,30,10,5,15};
    previousGeater(arr);
    return 0;
}