#include <iostream>
using namespace std;
int sumfun(int n=0){
    cout<<"enter n"<<endl;
    cin>>n;
    int i=1;
    int sum=0;
    while(i<=n){
        sum=i+sum;
        i++;
    }
    return sum;
}
int main(){
    int add=sumfun();
    cout<<add<<endl;
    return 0;
}