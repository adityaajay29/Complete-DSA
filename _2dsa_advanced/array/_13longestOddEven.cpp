#include <iostream>
#include <vector>
using namespace std;

int longestOddEven(vector<int>v,int n)
{
    int res=1;
    for(int i=0;i<n;i++)
    {
        int curr=1;
        for(int j=i+1;j<n;j++)
        {  
            if(v[j-1]%2==v[j]%2)
            {
                break;
            }
            else
            curr++;
        }
        res=max(curr,res);
    }
    return res;
}

int main()
{
    vector<int>v{1,2,3,4,5,6};
    int n=v.size();
    cout<<"longest Consecutive even odd is "<<longestOddEven(v,n)<<endl;
    return 0;
}