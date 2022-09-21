#include <iostream>
using namespace std;
void tower(int n,char startTower, char auxTower,char targetTower)
{
    // think for n=3
    if(n==1)
    {
    cout<<"move "<<"disk "<<"1"<<" from "<<startTower<<" to "<<targetTower<<endl;
    // simply return when reaching last disk
    return;
    }
    // now n=2, so think about 1st movement of 2,i.e, a to b, i.e, b becomes target, c becomes aux
    tower(n-1,startTower,targetTower,auxTower);
    cout<<"move "<<"disk "<<n<<" from "<<startTower<<" to "<<targetTower<<endl;
    // again n=2, so think about 2nd movement of 2,i.e, b to c, i.e, b becomes start, c becomes target

    tower(n-1,auxTower,startTower,targetTower);
}

int main()
{
    int n=3;
    tower(n,'A','B','C');
    return 0;
}
