#include <iostream>
using namespace std;
int search(int arr[],int n, int x){
    for(int i=0;i<n;i++){
        if(arr[i]==x)
            return i;
    }
        return -1;
}
int main(){
    int arr[]={20,5,7,25};
    int n=4;
    int x=20;
    int fun=search(arr,n,x);
    cout<<fun<<endl;
    return 0;
}
