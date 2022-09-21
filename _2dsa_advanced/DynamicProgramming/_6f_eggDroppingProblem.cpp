#include <iostream>
using namespace std;

// Problem statement: You are given N floor and K eggs. 
// You have to minimize the number of times you have to drop the eggs 
// to find the critical floor where critical floor means the floor 
// beyond which eggs start to break. Assumptions of the problem:

// If egg breaks at ith floor then it also breaks at all greater floors.
// If egg does not break at ith floor then it does not break at all lower floors.
// Unbroken egg can be used again.
// Note: You have to find minimum trials required to find the critical floor not the critical floor.

int eggDrop(int e, int f)
{
    // base cases : 
    if(f == 0 || f == 1)
    return f;

    if(e == 1)
    return f; 

    int attempts = INT_MAX;

    // candidates for k
    // all floors from 1 to f are eligible for threshold floor
    for(int k=1;k<=f;k++)
    {
        int breaks = eggDrop(e-1, k-1);
        int doesntBreak = eggDrop(e, f-k);

        // we have to find min attempts in worst case possible,
        // so we are taking max of whichever case, whether egg breaks or not
        // adding 1 to increase the attempt count by 1
        int tempAns = 1 + max(breaks, doesntBreak);
        attempts = min(attempts, tempAns);
    }
    return attempts;
}

int main()
{
    int e, f;
    cin>>e>>f;
    cout<<"the min no of attempts of dropping eggs to find the critical floor is "<<eggDrop(e, f)<<endl;
    return 0;
}

