#include <iostream>
using namespace std;
// int fibo(int n){ //space complexity of theta(n)
//     int f[n+1];
//     f[0]=0;
//     f[1]=1;
//     for(int i=2;i<=n;i++){
//         f[i]=f[i-1]+f[i-2];
//     }
//     for(int j=0;j<n;j++){
//         cout<<f[j]<<"->";
//     }
//     return f[n];
// }
int fib(int n){ //space complexity of theta(1)
    if(n==0||n==1){
        return n;
    }
    int c;
    int a=0,b=1;
    for(int i=2;i<=n;i++){
        c=a+b;
        a=b;
        b=c;
    }
    return c;
}
int main(){
    // int res=fibo(13);
    // cout<<res<<endl;
    int result=fib(9);
    cout<<result<<endl;
}