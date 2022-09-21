#include <iostream>
using namespace std;

// concept to use right shift operator
// anding(&) a digit with 1 will be 1 if LSB is set, else 0

int main()
{
    int x;
    int k;
    cout<<"enter x ";
    cin>>x;
    cout<<"enter k ";
    cin>>k;
    if((x>>(k-1)&1)==1)
    cout<<"yes, kth posi is set";
    else 
    cout<<"kth posi not set :(";
    return 0;
}