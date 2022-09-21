#include <iostream>
using namespace std;

void toh(int n, char s, char d, char h)
{
    // base case for last disk 
    if(n==1)
    {
        cout<<"move disk 1 from "<<s<<" to "<<d<<endl;
        return;
    }
    // we move all n-1 disks except the largest disk from a to b
    toh(n-1,s,h,d);
    // then we move the largest disk from a to c
    cout<<"move disk "<<n<<" from "<<s<<" to "<<d<<endl;
    // then we move rest n-1 disks from b to c
    toh(n-1,h,d,s);
}

int main()
{
    int n;
    char s='a';
    char h='b';
    char d='c';
    cin>>n;
    toh(n,s,d,h);
    return 0;
}