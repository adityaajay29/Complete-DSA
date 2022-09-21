#include <iostream>
#include <queue>
using namespace std;

struct myStack
{
    queue<int>q;
    queue<int>s;

    void pop()
    {
        if(q.empty())
        return;
        cout<<q.front();
    }
    void top()
    {
        if(q.empty())
        return;
        cout<<q.front();
    }
    void size()
    {
        if(q.empty())
        return;
        cout<<q.size();
    }
    void push(int x)
    {
        while(!q.empty())
        {
            s.push(q.front());
            q.pop();
        }
        q.push(x);
        while(!s.empty())
        {
            q.push(s.front());
            s.pop();        
        }
    }
};

int main()
{
    myStack st;
    st.push(20);
    st.push(7);
    st.push(16);
    st.push(11);
    st.push(12);
    st.top();
    st.pop();
    return 0;
}