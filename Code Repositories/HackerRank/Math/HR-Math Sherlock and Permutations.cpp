#include<iostream>
#define ll long long
using namespace std;
const ll mod=1e9+7;
ll fac[2005]={1};
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
ll inv(ll x) { return qpow(x,mod-2); }
int main()
{
    for(int i=1;i<=2000;i++)
        fac[i]=fac[i-1]*i%mod;
    int t,n,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        cout<<fac[n+m-1]*inv(fac[n])%mod*inv(fac[m-1])%mod<<endl;
    }
}