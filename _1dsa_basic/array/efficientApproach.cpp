#include <iostream>
using namespace std;
int largest(int arr[],int n){
    int result=0;
    for(int i=1;i<n;i++){
        if(arr[i]>arr[result])
        result=i;
    }
    return arr[result];
}
int main(){
    int n=6;
    int arr[]={5,8,20,10,30,40};
    cout<<largest(arr,n)<<endl;
    return 0;
}