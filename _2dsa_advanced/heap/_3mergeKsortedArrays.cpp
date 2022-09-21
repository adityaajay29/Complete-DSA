#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// approach : 1st put the 1st ele of all the arrays in pq
// then, pop the one with smallest element and put its element in the result array
// then, push the next ele of that array in the pq, if available
// continue till all ele no pushed
// time: O(nklog(k)), where k is the size of vector<vector>>, n is max ele in any array

struct myQueue
{
    int ele;
    int arrayPosi;
    int elePosi;
    myQueue(int e,int ap,int ep)
    {
        ele=e;
        arrayPosi=ap;
        elePosi=ep;
    }
};

// structure of our own comparision function
struct myComp
{
    // bool operator to create our comp func
    bool operator()(myQueue a,myQueue b)
    {
        return a.ele>b.ele;
    }
};

vector<int>mergedArray(vector<vector<int>>&v)
{
    int n=v.size();
    priority_queue<myQueue,vector<myQueue>,myComp>pq;
    for(int i=0;i<n;i++)
    {
        // put ele, its array's posi in v, element's posi in that array
        myQueue triplet(v[i][0],i,0);
        pq.push(triplet);
    }
    vector<int>ans;
    while(!pq.empty())
    {
        myQueue curr=pq.top();
        pq.pop();
        ans.push_back(curr.ele);
        int CurrElePosi=curr.elePosi;
        int currArrayPosi=curr.arrayPosi;
        // if next ele of array of popped ele is present, push that in pq
        if(CurrElePosi+1<v[currArrayPosi].size())
        {
            myQueue triplet(v[currArrayPosi][CurrElePosi+1],currArrayPosi,CurrElePosi+1);
            pq.push(triplet);
        }
    }
    return ans;
}

int main()
{
    vector<vector<int> >v{
        {2,8,9},
        {1,3,17},
        {0,5,12}
    };
    vector<int>ans=mergedArray(v);
    for(auto x:ans)
    cout<<x<<" ";
    return 0;
}