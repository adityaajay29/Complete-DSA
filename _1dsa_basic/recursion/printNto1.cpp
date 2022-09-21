#include <iostream>
using namespace std;
void nums(int n)
{
    if(n<1) //handling cases for -ve nos also
    return;
    else
    {
    cout<<n<<" "; //1st printing, then calling fun for lower number
    nums(n-1); //tail recursive as the recursive call is in the end
    }
}

int main()
{
    nums(5);
    return 0;
}