#include <iostream>
using namespace std;
int seclargest(int arr[], int n)
{
    int result=-1,largest=0; //initialising 2nd largest as -1 and largest as 0
    for(int i=1;i<n;i++)
    {
        if(arr[i]>arr[largest])
        {
            result=largest;
            largest=i;
        }
        else if(arr[i]!=arr[largest])
        {
            if(result==-1 || arr[i]>arr[result])
            result=i;
        }
    }
    return result;
}
int main(){
    int n=5;
    int arr[]={5,20,12,10,20};
    seclargest(arr,n);
    cout<<seclargest(arr,n)<<endl;
    return 0;
}