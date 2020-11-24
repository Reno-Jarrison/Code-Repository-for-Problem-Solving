#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2e6;
int dp[2][maxn];
int main()
{
    int t,n,m,k,tag,ks=0,lim=1<<20;
    scanf("%d",&t);
    while(t--)
    {
        cin>>n>>m;
        memset(dp,0,sizeof(dp));
        dp[tag=0][0]=1;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&k),tag=!tag;
            for(int j=0;j<lim;j++)
                dp[tag][j]=dp[!tag][j]+dp[!tag][j^k];
        }
        ll ans=0;
        for(int i=m;i<lim;i++)
            ans+=dp[tag][i];
        printf("Case #%d: %lld\n",++ks,ans);
    }
}
