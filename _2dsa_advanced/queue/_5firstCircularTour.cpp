#include <iostream>
#include <vector>
using namespace std;

// prob:given 2 arrays, 1 having capacity of each petrol pumps
// 2nd having distanc of next pump from it
// we have to find the pump from which if a truck starts, can complete the tour and come back at the start posi

int posi(vector<int>cap,vector<int>dist)
{
    int n=cap.size();
    int start;
    for(start=0;start<n;start++)
    {
        int end=start;
        int curr=0;
        while(true)
        {
            curr+=cap[end]-dist[end];
            if(curr<0)
            break;
            end=(end+1)%n;
            // if end again becomes start, it means circle completed
            if(end==start)
            return start+1;
        }
    }
    return -1;
}

int main()
{
    vector<int>cap{4,8,7,4};
    vector<int>dist{6,5,3,5};
    cout<<" we can start from pump number "<<posi(cap,dist)<<endl;
    return 0;
}