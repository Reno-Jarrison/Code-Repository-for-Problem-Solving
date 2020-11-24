#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=55;
ll fib[maxn]={1,1};
int main()
{
    for(int i=2;i<=50;i++)
        fib[i]=fib[i-1]+fib[i-2];
    int x;
    while(~scanf("%d",&x))
        printf("%lld\n",fib[x]);
}