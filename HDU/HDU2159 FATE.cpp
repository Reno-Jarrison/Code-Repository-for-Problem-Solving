#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=105,inf=0x3f3f3f3f;
int dp[maxn][2*maxn];
int main()
{
    int n,m,k,s,w,c;
    while(cin>>n>>m>>k>>s)
    {
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=k;i++)
        {
            cin>>w>>c;
            for(int j=1;j<=s;j++)
                for(int k=c;k<=m;k++)
                    dp[j][k]=max(dp[j][k],dp[j-1][k-c]+w);
        }
        int ans=-1;
        for(int i=m;i;i--)
            if(dp[s][i]>=n) ans=m-i;
        cout<<ans<<endl;
    }
}