#include <iostream>
#include <vector>
using namespace std;

// SORTED ARRAY
// TWO POINTERS APPROACH
// tc:O(n)

bool pairAsSum(vector<int>arr,int x)
{
    int l=0;
    int h=arr.size()-1;
    while(l<h)
    {
        if((arr[l]+arr[h])==x)
        return true;
        else if(x<(arr[l]+arr[h]))
        h--;
        else
        l++;
    }
    return false;
}

int main()
{
    vector<int>arr{2,5,8,12,30};
    int x=20;
    cout<<pairAsSum(arr,x)<<endl;
    return 0;
}

