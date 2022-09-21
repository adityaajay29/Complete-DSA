#include <iostream>
#include <unordered_set>
using namespace std;

// no repeatition in unordered s, used when keys are not repeated

int main()
{
    unordered_set<int>s;
    s.insert(10);
    s.insert(5);
    s.insert(20);
    s.insert(15);
    for(auto i=s.begin();i!=s.end();i++) //traversal
    {
        cout<<*i<<endl;
    }
    // int arr[]={12,34,1,77,6};
    // for(auto x:arr)
    // s.insert(x);
    // for(auto &x:s) //checking for all x in s, printing values of that x
    // {
    // cout<<x<<endl;
    // }
    // cout<<s.size()<<endl;
     // s.clear();
    // cout<<s.size()<<endl;
    // if(s.find(20)==s.end())
    // cout<<"not found"<<endl;
    // else
    // cout<<"found "<<*s.find(20)<<endl; //* used for dereffering since found func rerurns address, not value 
    // s.insert(15);
    // cout<<s.size()<<endl;
    // s.erase(15);
    // cout<<s.size()<<endl;
    // s.erase(15);
    // cout<<s.size()<<endl;
    return 0;
}