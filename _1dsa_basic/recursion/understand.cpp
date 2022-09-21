#include <iostream>
using namespace std;
void fun(int n)
{
    if
    (n<1) //base case
    // after execution of base case, the fun unwinds
    return; //returning control/value to parent
    else
    {
        cout<<n<<endl; //will execute if n not 0
        fun(n-1); //function will be called again from start
        cout<<n<<endl; //after n=0, returned to parent starting from 1, completes all the tasks,then returns to parent
        cout<<n+1<<endl;
        cout<<n<<endl;
    }
}

int main()
{
    int n=3;
    fun(n);
}