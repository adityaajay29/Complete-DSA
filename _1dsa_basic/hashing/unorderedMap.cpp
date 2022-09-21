#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    // unordered_map<string,int>umap;
    // umap["adi"]=10;
    // umap["srikar"]=19;
    // umap["tanya"]=5;
    // for(auto x:umap)
    // cout<<x.first<<" "<<x.second<<endl;
    // umap.erase("adi");
    // cout<<umap.size()<<endl;

    unordered_map<string,pair<int,int> >umap;
    umap["adi"]={2,3};
    umap["mummy"]={8,4};
    umap["adi"]={16,9};
    umap["tanya"]={89,23};
    umap["papa"]={34,45};

    for(auto x:umap)
    cout<<x.first<<" "<<x.second.first<<" "<<x.second.second<<endl;
    return 0;
}