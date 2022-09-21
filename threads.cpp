#include <iostream>
#include <thread>
#include <vector>
using namespace std;

void findSum(long long &sum, long long start, long long end)
{
    sum = 0;
    for(long long i=start;i<end;i++)
    {
        sum += i;
    }
}   

int main()
{
    int threads = 2;
    int start = 0;
    long long end = 1000 * 1000 * 1000;
    long long steps = end / threads;

    vector<long long> v(2);
    thread th1(findSum, ref(v[0]), start, steps);
    thread th2(findSum, ref(v[1]), steps, end);

    th1.join();
    th2.join();

    long long total  = v[0] + v[1];
    cout<<"the individual sum are "<<v[0]<<" "<<v[1]<<endl;
    cout<<"the total sum is "<<total<<endl;
    return 0;
}