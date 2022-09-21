#include <iostream>
using namespace std;
int hashFun(int key,int n)
{
    return key%n;
}

int search(int arr[],int key,int n)
{
    int hash=hashFun(key,n);
    int i=hash;
    while(arr[i]!=-1)
    {
        if(arr[i]==key)
        return true;
        i=(i+1)%n;
        if(i==hash)
        return false;
    }
    return false;
}

int insert(int *arr,int key,int n)
{
    int hash=hashFun(key,n);
    int i=hash;
    if(arr[i]==-1)
    arr[i]=key;
    while(arr[i]!=-1)
    {
        i=(i+1)%n;
        if(i==hash)
        return false;
    }
    arr[i]=key;
}

bool erase(int *arr,int key,int n)
{
    int hash=hashFun(key,n);
    int i=hash;
    while(arr[i]!=-1)
    {
        if(arr[i]==key)
        {
            arr[i]=-2;
            return true; //can be deleted
        }
        i=(i+1)%n;
        if(i==hash)
        return false;
    }
    return false;
}