#include <iostream>
#include <vector>
using namespace std;

class result
{
    private : 
    int roll;
    string name;
    vector<int> marks;

    public :
    void getName(string s)
    {
        name = s;
    }
    void getRoll(int r)
    {
        roll = r;
    }
    void getMarks(vector<int> arr)
    {
        marks = arr;
    }
    int totalMarks();
    char grade();
};

int main()
{
    result r1;
    vector<int> arr{10, 20, 15};
    r1.getMarks(arr);
    r1.getName("aditya");
    r1.getRoll(2);
    cout<<r1.totalMarks()<<endl;
    cout<<r1.grade()<<endl;
}

int result :: totalMarks()
{
    int res = 0;
    for(int x : marks)
        res += x;

    return res;
}

char result :: grade()
{
    int res = totalMarks();
    return (res >= 65 ? 'P' : 'F');
}