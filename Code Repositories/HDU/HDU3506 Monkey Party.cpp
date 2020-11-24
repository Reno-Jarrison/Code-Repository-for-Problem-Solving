#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=2e3+5,inf=0x3f3f3f3f;
int a[maxn],s[maxn],dp[maxn][maxn],p[maxn][maxn];
int sum(int l,int r)
{    return s[r]-s[l-1]; }
int main()
{
    int n;
    while(cin>>n)
    {
        for(int i=1;i<=n;i++) 
            cin>>a[i],a[i+n]=a[i];
        for(int i=1;i<n*2;i++)
            s[i]=s[i-1]+a[i],p[i][i]=i;
        for(int i=2;i<=n;i++)
            for(int l=1,r=l+i-1;r<=2*n;l++,r++)
            {
                dp[l][r]=inf;
                for(int j=p[l][r-1];j<=p[l+1][r];j++)
                    if(dp[l][r]>=dp[l][j]+dp[j+1][r]+sum(l,r))
                        dp[l][r]=dp[l][j]+dp[j+1][r]+sum(l,r),p[l][r]=j;
            }
        int ans=inf;
        for(int i=1;i<=n;i++)
            ans=min(ans,dp[i][i+n-1]);
        cout<<ans<<endl;
    }
}