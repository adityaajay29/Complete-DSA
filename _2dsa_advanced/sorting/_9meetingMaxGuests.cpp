#include <iostream>
#include <vector>
using namespace std;

// prob: you have to visit a party timed from 0000 to 2359
// you have to go to party such that you meet max no of guests
// you have been given the arr and dep time of all the guests

int maxGuests(vector<int>arr,vector<int>dep,int n)
{
    sort(arr.begin(),arr.end());
    sort(dep.begin(),dep.end());
    // 1st time of arr will surely be les than the 1st time of dept
    int a=1;
    int d=0;
    int res=1;
    int curr=1;
    while(a<n && d<n)
    {
        // if arr time is less than dep time, guests arr added
        if(arr[a]<=dep[d])
        {
            a++;
            curr++;
        }
        // else guest has left, move to next dep time
        else 
        {
            curr--;
            d++;
        }
        res=max(res,curr);
    }
    return res;
}

int main()
{
    vector<int>arr{900,600,700};
    vector<int>dep{1000,800,730};
    int n=arr.size();
    cout<<"the max guests you can meet is "<<maxGuests(arr,dep,n)<<endl;
    return 0;
}