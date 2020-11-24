#include<cstdio>
#include<cmath>
#define ll long long
using namespace std;
const int maxn=1e5+5;
const ll mod=1e9+7;
ll fac[maxn]={1},inv[maxn];
ll qpow(ll a,ll b)
{
    ll ans=1;
    while(b)
    {
        if(b&1) ans=ans*a%mod;
        a=a*a%mod,b>>=1;
    }
    return ans;
}
int main()
{
    for(int i=1;i<maxn;i++)
        fac[i]=fac[i-1]*i%mod,inv[i]=qpow(i,mod-2);
    int t; ll x,tmp;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld",&x);
        if(x<=4) { printf("%lld\n",x); continue; }
        tmp=sqrt(x*2);
        while(tmp*(tmp+1)/2-1>x) tmp--;
        ll r=x-tmp*(tmp+1)/2+1,ans;
        if(!r) ans=fac[tmp];
        else if(r==tmp) ans=fac[tmp+2]*inv[2]%mod*inv[tmp+1]%mod;
        else ans=fac[tmp+1]*inv[tmp+1-r]%mod;
        printf("%lld\n",ans);
    }
}