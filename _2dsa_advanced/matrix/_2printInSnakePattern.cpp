#include <iostream>
#include <vector>
using namespace std;

void snakePattern(vector<vector<int> >&arr)
{
    for(int i=0;i<arr.size();i++)
    {
        if(i%2==0)
        {
            for(int j=0;j<arr[i].size();j++)
            {
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }
        else 
        {
            for(int j=arr[i].size()-1;j>=0;j--)
            {
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
}

int main()
{
    vector<vector<int> >arr{{1,2,3},{4,5,6},{7,8,9}};
    snakePattern(arr);
    return 0;
}