#include <iostream>
#include <string>
#include <map>
using namespace std;

string minimumPossibleN(int f, int k) {
    map<string,string>mp;
    int i=f;
    while(mp[to_string(i)].size()==0)
    {
        int m=0;
        int j=i;
        while(j)
        {
            m+=(j%10);
            j/=10;
        }
        if(mp[to_string(m)].size()!=0) 
        break;
        mp[to_string(m)]=to_string(i);
        i+=f;
    }
    if(mp[to_string(k)].size()) 
    return mp[to_string(k)];
    return "-1";
}
int main(){
    cout<<minimumPossibleN(7,8);
}