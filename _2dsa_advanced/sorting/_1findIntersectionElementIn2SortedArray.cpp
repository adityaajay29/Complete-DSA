#include <iostream>
#include <vector>
using namespace std;

// using concept of merge function
// O(n1+n2) time

vector<int> intersection(vector<int>arr1,vector<int>arr2)
{
    vector<int>ans;
    int n1=arr1.size();
    int n2=arr2.size();
    int i=0;
    int j=0;
    while(i<n1 && j<n2)
    {
        // avoid duplicates in first array
        // if duplicate, then increment i and continue 
        if(i>0 && arr1[i]==arr1[i-1])
        {
            i++;
            continue;
        }
        // increment pointer of whichever has smaller element, so that there can be possibility of intersection
        else if(arr1[i]<arr2[j])
        i++;
        else if(arr2[j]<arr1[i])
        j++;
        // if found intersection, add to the ans and increment both pointers
        else 
        {
            ans.push_back(arr1[i]);
            i++;
            j++;
        }
    }
    return ans;
}

int main()
{
    vector<int>arr1{1,1,3,3,5};
    vector<int>arr2{1,1,1,1,3,5,7};
    cout<<"intersection of elements is ";
    vector<int>ans=intersection(arr1,arr2);
    for(auto x:ans)
    cout<<x<<" ";
    cout<<endl;
    return 0;
}