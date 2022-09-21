#include <vector>
#include <iostream>
using namespace std;

// the matrix is row and column wise sorted
// trick : start traversal from top right
// if x is smaller goto left
// if x is larger goto bottom

void isPresent(vector<vector<int> > arr,int x)
{
    int n=arr.size();
    // optimisation
    if(x<arr[0][0] || x>arr[n-1][n-1])
    {
        cout<<"not found"<<endl;
        return;
    }
    int i=0;
    int j=n-1;
    while(i<n && j>=0)
    {
        if(arr[i][j]==x)
        {
        cout<<i<<","<<j<<endl;
        return;
        }
        else if(x<arr[i][j])
        j--;
        else 
        i++;
    }
    cout<<"not found"<<endl;
}

int main()
{
    vector<vector<int> >arr{
        {10,20,30},
        {15,25,35},
        {27,29,37}
    };
    int x=29;
    isPresent(arr,x);
    return 0;
}