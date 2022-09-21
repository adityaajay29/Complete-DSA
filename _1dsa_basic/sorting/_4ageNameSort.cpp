#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct people
{
    string name;
    int age;
};

bool myComp(people p1,people p2)
{
    if(p1.age==p2.age)
    return (p1.name<p2.name);
    else
    // lesser age will be before
    return (p1.age<p2.age);
}

int main()
{
    vector<people>v{{"aditya",22},{"tanya",20},{"srikar",20},{"jb",21}};
    sort(v.begin(),v.end(),myComp);
    for(auto x:v)
    cout<<x.name<<" "<<x.age<<",";
    cout<<endl;
    return 0;
}