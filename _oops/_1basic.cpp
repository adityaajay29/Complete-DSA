#include <iostream>
#include <vector>
using namespace std;

class rectangle
{
    private : 
    int l;
    int b;

    public :

    rectangle(int len, int bre)
    {
        l = len;
        b = bre;
    }

    // void setLen(int len)
    // {
    //     l = (len > 0 ? len : 0);
    // }
    // int getLen()
    // {
    //     return l;
    // }
    // void setBre(int bre)
    // {
    //     b = (bre > 0 ? bre : 0);
    // }
    // int getBre()
    // {
    //     return b;
    // }

    int area()
    {
        return l * b;
    }
    int peri();
};

int rectangle :: peri()
{
    return ((l && b) ? 2 * (l + b) : 0);
}

int main()
{
    // allocation in stack
    // rectangle r1;
    // r1.l;
    // r1.b;
    // r1.area();
    // r1.peri();
    // **********************
    // rectangle *ptr;
    // ptr = &r1;
    // ptr->l = 5;
    // ptr->b = 10;
    // cout<<ptr->area()<<" "<<ptr->peri()<<endl;

    // **********************
    // dynamic alloaction in heap
    // rectangle *r2 = new rectangle();
    // r2->l;
    // r2->b;
    // cout<<r2->area()<<endl;
    // cout<<r2->peri()<<endl;
    
    rectangle r1(5, 10);
    // r1.setLen(-5);
    // r1.setBre(10);
    // cout<<r1.getLen()<<" "<<r1.getBre()<<endl;
    cout<<r1.area()<<" "<<r1.peri()<<endl; 
    return 0;
}