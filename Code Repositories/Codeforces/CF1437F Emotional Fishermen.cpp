#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=5e3+5,mod=998244353;
ll a[maxn],pos[maxn],dp[maxn][maxn],s[maxn][maxn];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
        pos[i]=upper_bound(a+1,a+n+1,a[i]/2)-a-1;
    dp[0][0]=1;
    fill(s[0],s[0]+n+1,1);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            dp[i][j]=dp[i-1][j]*max(pos[j]-i+2,0LL);
            dp[i][j]=(dp[i][j]+s[i-1][pos[j]])%mod;
            s[i-1][j]=s[i-1][j-1]+dp[i-1][j];
        }
    printf("%lld\n",dp[n][n]);
}