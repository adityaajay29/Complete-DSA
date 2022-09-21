#include <iostream>
#include <stack>
using namespace std;

// it is a container adapter data structure, as it acts as an interface of different data structure 
// by which it is implemented
// can be implemented using list, vector, dequeue

int main()
{
    stack<int>s;
    cout<<s.size()<<endl;
    s.push(10);
    s.push(20);
    s.push(30);
    cout<<s.size()<<endl;
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    cout<<s.empty()<<endl;
    return 0;
}