#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2e3+5;
const ll mod=1e9+7;
ll dp[maxn][maxn],C[maxn][maxn],A[maxn]={1};
void init(int n)
{
    for(int i=1;i<=n;i++) dp[i][1]=1;
    for(int i=2;i<=n;i++)
        for(int j=2;j<=i;j++)
            dp[i][j]=(dp[i-1][j]*j+dp[i-1][j-1])%mod;
    for(int i=1;i<=n;i++) 
        A[i]=A[i-1]*i%mod;
    for(int i=1;i<=n;i++)
    {
        C[i][0]=C[i][i]=1;
        for(int j=1;j<i;j++)
            C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
    }
}
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
    init(2000);
    int t,n,m;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        ll ans=0;
        for(int i=1;i<=min(n,m-1);i++)
            ans=(ans+C[m][i]*dp[n][i]%mod*A[i]%mod*qpow(m-i,n)%mod)%mod;
        printf("%lld\n",ans);
    }
}