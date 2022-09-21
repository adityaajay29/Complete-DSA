#include <iostream>
#include <vector>
using namespace std;

int josephus(int index, int k, vector<int> ans)
{
    // base case : return the left guy
    if(ans.size() == 1)
    {
        return ans[0];
    }
    // updating the current killer
    // modulo to go in circle in the array
    // k is already used after decrement in main function
    index = (index + k) % ans.size();
    // killed person is removed from the array
    ans.erase(ans.begin() + index);
    return josephus(index, k, ans);
}

int main()
{
    int n, k;
    cin>>n>>k;
    k--;
    vector<int> ans;
    for(int i=1;i<=n;i++)
    {
        ans.push_back(i);
    }
    cout<<"the safe position is "<<josephus(0, k, ans)<<endl;
    return 0;
}
