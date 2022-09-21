#include <iostream>
#include <queue>
using namespace std;

// prob : print all the 1st n numbers which have only 5 or 6 or both

void printNum(int n)
{
    queue<string>q;
    q.push("5");
    q.push("6");
    for(int i=0;i<n;i++)
    {
        string temp=q.front();
        q.pop();
        cout<<temp<<" ";
        q.push(temp+"5");
        q.push(temp+"6");
    }
    cout<<endl;
}

int main()
{
    int n=1000;
    printNum(n);
    return 0;
}