#include<bits/stdc++.h>
using namespace std;
const int maxn=1005,mod=10007;
char s[maxn];
int dp[maxn][maxn];
int main()
{
    int t,n,ks=0;
    cin>>t;
    while(cin>>(s+1))
    {
        n=strlen(s+1);
        for(int i=1;i<=n;i++) 
            dp[i][i]=1;
        for(int i=2;i<=n;i++)
            for(int l=1,r=l+i-1;r<=n;l++,r++)
            {
                dp[l][r]=(dp[l][r-1]+dp[l+1][r]-dp[l+1][r-1]+mod)%mod;
                if(s[l]==s[r]) dp[l][r]=(dp[l][r]+dp[l+1][r-1]+1)%mod;
            }
        cout<<"Case "<<++ks<<": "<<dp[1][n]<<endl;
    }
}