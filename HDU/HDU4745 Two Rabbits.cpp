#include<iostream>
using namespace std;
const int maxn=3e3+5;
int a[maxn],dp[maxn][maxn];
int main()
{
    int n;
    while(cin>>n&&n)
    {
        for(int i=1;i<=n;i++) 
            cin>>a[i],dp[i][i]=1;
        for(int i=2;i<=n;i++)
            for(int l=1,r=l+i-1;r<=n;l++,r++)
            {
                dp[l][r]=max(dp[l+1][r],dp[l][r-1]);
                if(a[l]==a[r]) 
                    dp[l][r]=max(dp[l][r],dp[l+1][r-1]+2);
            }
        int ans=dp[1][n];
        for(int i=1;i<=n;i++)
            ans=max(ans,dp[1][i]+dp[i+1][n]);
        cout<<ans<<endl;
    }
}