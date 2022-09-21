#include <iostream>
using namespace std;
int hashNums(int keys)
{
    int bucket;
    cout<<"enter the size of hash table"<<endl;
    cin>>bucket;
    return keys%bucket;
}

// int hashStr(string key)
// {
//     int bucket;
//     cout<<"enter the size of hash table"<<endl;
//     cin>>bucket;
//     int len=key.length();
//     for(int i=0;i<len;i++)
//     {
//         int index=key[i]
//     }
// }

int main()
{
    int keys;
    cout<<"enter key"<<endl;
    cin>>keys;
    cout<<hashNums(keys)<<endl;
    return 0;
}