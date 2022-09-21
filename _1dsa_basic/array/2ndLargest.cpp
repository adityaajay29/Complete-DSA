#include <iostream>
using namespace std;
int largest(int arr[],int n){
    int result=0;
    for(int i=1;i<n;i++){
        if(arr[i]>arr[result])
        result=i;
    }
    return result;
}
int secLarge(int arr[],int n){
    int result=largest(arr,n);
    int res=-1;
    for(int i=0;i<n;i++)
    {
        if(arr[i]!=arr[result])
        {
            if(res==-1)
            res=i;
            else if(arr[i]>arr[res])
            res=i;
        }
    }
    return res;
}
int main(){
    int n=5;
    int arr[]={5,20,12,10,20};
    largest(arr,n);
    cout<<largest(arr,n)<<endl;
    cout<<secLarge(arr,n)<<endl;
    return 0;
}