#include <iostream>
#include <vector>
using namespace std;

// problem : find the max area of water that can be stored between any two bars 
// distance between bars is 1 unit

int maxWater(vector<int>&bars)
{
    int maxArea=0;
    int l=0;
    int n=bars.size();
    int h=n-1;
    while(l<h)
    {
        int area=min(bars[h],bars[l])*(h-l);
        maxArea=max(maxArea,area);
        if(bars[l]<bars[h])
        l++;
        else
        h--;
    }
    return maxArea;
}

int main()
{
    vector<int>bars{1,7,2,3,8,2};
    cout<<"max water between the bars can be "<<maxWater(bars)<<endl;
    return 0;
}
