#include <iostream>
#include <vector>
using namespace std;

// concept:
// create a comp func to sort the intervals in increasing order of their start
// check if the 2 intervals overlap, by checking if start of 2nd is smaller than the end of 1st
// if so, then create the new merged interval from smallest of start of both 
// to largest of end of both
// if not, then increment the res, and overwrite the new interval in res index

struct interval
{
    int start;
    int end;
};

bool myComp(interval x1,interval x2)
{
    return (x1.start<x2.start);
}

void mergeIntervals(vector<interval>arr,int n)
{
    sort(arr.begin(),arr.end(),myComp);
    // res variable to store the no. of overlaps 
    // assuming 1st interval is overlaped
    int res=0;
    for(int i=1;i<n;i++)
    {
        if(arr[res].end>=arr[i].start)
        {
            arr[res].start=min(arr[res].start,arr[i].start);
            arr[res].end=max(arr[res].end,arr[i].end);
        }
        else
        {
            // incrementing no. of overlaps
            res++;
            // overwriting it with current posi of res
            arr[res]=arr[i];
        }
    }
    for(int i=0;i<=res;i++)
    cout<<arr[i].start<<","<<arr[i].end<<endl;
}

int main()
{
    vector<interval>arr{{5,10},{3,15},{18,30},{2,7},{18,35}};
    int n=arr.size();
    mergeIntervals(arr,n);
    return 0;
}