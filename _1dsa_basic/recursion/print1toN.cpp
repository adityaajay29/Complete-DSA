#include <iostream>
using namespace std;
void nums(int n)
{
    if(n==0)
    return; //returning control to parent
    else
    {
        nums(n-1); //1st calling the func to reach lowest num, then print the nums 
        cout<<n<<" "; //cause we want to print 4 before 5
    }
}
int main()
{
    nums(5);
}