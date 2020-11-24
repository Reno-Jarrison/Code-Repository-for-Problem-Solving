#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e6+5;
const ll inf=1e12;
int a[maxn];
ll dp[maxn],mxv[maxn];
int main()
{
    int n,m;
    while(~scanf("%d%d",&m,&n))
    {
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        for(int i=0;i<=n;i++) mxv[i]=0;
        for(int i=1;i<=m;i++)
        {
            for(int j=i;j<=n;j++)
                dp[j]=max(dp[j-1],mxv[j-1])+a[j];
            mxv[i-1]=-inf;
            for(int j=i;j<=n;j++)
                mxv[j]=max(mxv[j-1],dp[j]);
        }
        printf("%lld\n",mxv[n]);
    }
}