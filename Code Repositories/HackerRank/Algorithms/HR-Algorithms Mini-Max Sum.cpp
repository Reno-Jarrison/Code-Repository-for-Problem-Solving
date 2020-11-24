#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
int main()
{
    ll x,sum=0,mxv=1,mnv=1e9;
    for(int i=1;i<=5;i++)
    {
        scanf("%lld",&x);
        sum+=x,mxv=max(mxv,x),mnv=min(mnv,x);
    }
    printf("%lld %lld",sum-mxv,sum-mnv);
}