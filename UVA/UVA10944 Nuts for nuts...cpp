#include<bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
int dp[1<<15][15],x[20],y[20];
int dist(int a,int b)
{	return max(abs(x[a]-x[b]),abs(y[a]-y[b])); }
void update(int& cur,int val)
{	cur=min(cur,val); }
int main()
{
	int n,m;
	while(~scanf("%d%d",&n,&m))
	{
		int idx=0,px,py;
		for(int i=1;i<=n;i++)
		{
			char s[25];
			scanf("%s",s+1);
			for(int j=1;j<=m;j++)
			{
				if(s[j]=='L') px=i,py=j;
				if(s[j]=='#')
					x[idx]=i,y[idx]=j,idx++;
			}
		}
		if(!idx)
		{	puts("0"); continue; }
		x[idx]=px,y[idx]=py;
		memset(dp,inf,sizeof(dp));
		for(int i=0;i<idx;i++) 
			dp[1<<i][i]=dist(i,idx);
		for(int i=1;i<(1<<idx);i++)
		{
			int sta=i;
			for(int j=0;j<idx&&sta;j++,sta>>=1)
			{
				if(!(sta&1)) continue;
				for(int k=0;k<idx;k++)
					if(!(i&(1<<k)))
						update(dp[i|(1<<k)][k],dp[i][j]+dist(j,k));
			}
		}
		int ans=inf;
		for(int i=0;i<idx;i++)
			update(ans,dp[(1<<idx)-1][i]+dist(i,idx));
		printf("%d\n",ans);
	}	
}