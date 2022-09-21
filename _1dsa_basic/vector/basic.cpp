#include <iostream>
#include <vector>
using namespace std;
void vect(vector<int>v)
{
    for(int i=0;i<5;i++)
        v.push_back(i+1);
}

int main()
{
    vector<int>v{1,2,3,4};
    for(auto x:v)
    cout<<x<<" ";
}