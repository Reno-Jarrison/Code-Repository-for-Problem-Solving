#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e3+5;
const ll inf=1e12;
ll a[maxn],dp[maxn];
int main()
{
    int n;
    while(scanf("%d",&n)&&n)
    {
        ll ans=-inf;
        for(int i=1;i<=n;i++)
        {
            scanf("%lld",&a[i]),dp[i]=a[i];
            for(int j=1;j<i;j++)
                if(a[i]>a[j]) dp[i]=max(dp[i],dp[j]+a[i]);
            ans=max(ans,dp[i]);
        }
        printf("%lld\n",ans);
    }
}