#include<cstdio>
#include<cmath>
#define ll long long
using namespace std;
int gcd(int a,int b)
{    return !b?a:gcd(b,a%b); }
int main()
{
    int a,b;
    while(~scanf("%d%d",&a,&b))
    {
        int d=gcd(a,b),a0=a/d,b0=b/d,ok=1;
        ll delta=1LL*a0*a0-4LL*b0,x1,x2;
        if(delta<0) ok=0;
        else
        {
            ll tmp=sqrt(delta);
            if(tmp*tmp!=delta||(a0+tmp)%2) ok=0;
            x1=(a0-tmp)>>1,x2=(a0+tmp)>>1;
        }
        if(ok) printf("%lld %lld\n",x1*d,x2*d);
        else puts("No Solution");
    }
}