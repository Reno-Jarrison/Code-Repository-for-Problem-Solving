#include<bits/stdc++.h>
using namespace std;
const int maxn=105,inf=0x3f3f3f3f;
int s[maxn],dp[maxn][maxn];
int main()
{
    int t,n,a,b,p;
    cin>>t;
    while(t--)
    {
        cin>>n>>a>>b>>p,p=min(p,n);
        for(int i=0;i<n;i++) cin>>s[i];
        memset(dp,-inf,sizeof(dp));
        int ans=dp[0][0]=s[0];
        for(int i=1;i<n;i++)
            for(int j=1;j<=p;j++)
            {
                for(int k=max(0,i-b);k<=i-a;k++)
                    dp[j][i]=max(dp[j][i],dp[j-1][k]+s[i]);
                ans=max(ans,dp[j][i]);
            }
        cout<<ans<<endl;
    }
}