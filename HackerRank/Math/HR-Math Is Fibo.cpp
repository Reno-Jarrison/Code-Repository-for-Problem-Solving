#include<iostream>
#include<set>
#define ll long long
using namespace std;
ll fib[60]={0,1},n;
set<ll>s;
int main()
{
    for(int i=2;i<60;i++)
        fib[i]=fib[i-1]+fib[i-2],s.insert(fib[i]);
    int t;
    cin>>t;
    while(t--) cin>>n,puts(s.count(n)?"IsFibo":"IsNotFibo");
}