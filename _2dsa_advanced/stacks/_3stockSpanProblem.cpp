#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// start with 0th index
// push it in stack
// if we find top is smaller than the curr ele
// we pop that index from the stack and print the span, then add curr to stack 
// else simply add the curr
//  *******IMPORTANT TO 1ST PRINT THE SPAN BEFORE PUSHING IN THE STACK, AS WE WANT PREVIOUS TOP VALUE*********
// O(n) solution


// naive appr : O(n2)
// void stockSpan(vector<int>&days)
// {
//     vector<int>span;
//     int n=days.size();
//     for(int i=0;i<n;i++)
//     {
//         int count=1;
//         for(int j=i-1;j>=0;j--)
//         {
//             if(days[j]<=days[i])
//             count++;
//             else 
//             break;
//         }
//         span.push_back(count);
//     }
//     for(auto x:span)
//     cout<<x<<" ";
// }

// eff approach
void stockSpan(vector<int>days)
{
    stack<int>s;
    int n=days.size();
    // pushig the 1st index
    s.push(0);  
    cout<<1<<" ";
    for(int i=1;i<n;i++)
    {   
        // only enters the loop when ele is larger than the top index ele
        while(!s.empty() && days[s.top()]<=days[i])
        {
            s.pop();
        }

        // 1st print the span 
        if(s.empty())
        cout<<i+1<<" ";
        else
        cout<<i-s.top()<<" ";
        // then push that ele index in stack
        s.push(i);
    }
}

int main()
{
    vector<int>days{15,13,12,14,16,8,6,4,10,30};
    stockSpan(days);
    cout<<endl;
    return 0;
}