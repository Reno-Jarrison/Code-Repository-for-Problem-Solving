#include<bits/stdc++.h>
using namespace std;
const int maxn=25,inf=0x3f3f3f3f;
int dp[maxn][maxn][maxn][maxn],sum[maxn][maxn];
int cnt(int xl,int xr,int yl,int yr)
{    return sum[xr][yr]+sum[xl-1][yl-1]-sum[xr][yl-1]-sum[xl-1][yr]; }
int main()
{
    int n,m,k,x,y,ks=0;
    while(cin>>n>>m>>k)
    {
        memset(sum,0,sizeof(sum));
        for(int i=1;i<=k;i++) 
            cin>>x>>y,sum[x][y]++;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                sum[i][j]+=sum[i][j-1]+sum[i-1][j]-sum[i-1][j-1];
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                for(int xl=1,xr=xl+i-1;xr<=n;xl++,xr++)
                    for(int yl=1,yr=yl+j-1;yr<=m;yl++,yr++)
                    { 
                        int &val=dp[xl][xr][yl][yr];
                        if(cnt(xl,xr,yl,yr)==1) 
                        {    val=0; continue; }
                        val=inf;
                        for(int k=xl;k<xr;k++)
                            if(cnt(xl,k,yl,yr)&&cnt(k+1,xr,yl,yr))
                                val=min(val,dp[xl][k][yl][yr]+
                                    dp[k+1][xr][yl][yr]+yr-yl+1);
                        for(int k=yl;k<yr;k++)
                            if(cnt(xl,xr,yl,k)&&cnt(xl,xr,k+1,yr))
                                val=min(val,dp[xl][xr][yl][k]+
                                    dp[xl][xr][k+1][yr]+xr-xl+1);
                    }
        cout<<"Case "<<++ks<<": "<<dp[1][n][1][m]<<endl;
    }
}