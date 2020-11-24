#include<bits/stdc++.h>
using namespace std;
const int maxn=105,inf=0x3f3f3f3f;
int c[maxn],sta[maxn],dp[maxn][1<<8][1<<8],s,m,n;
int dfs(int step,int sta1,int sta2)
{
	if(step>n) return sta2==(1<<s)-1?0:inf;
	if(~dp[step][sta1][sta2]) return dp[step][sta1][sta2];
	int ans=dfs(step+1,sta1,sta2);
	int nxt1=sta1,nxt2=sta2,bit=sta[step],cnt=0;
	while(bit)
	{
		if(bit&1)
		{
			if(nxt1&(1<<cnt)) nxt2|=1<<cnt;
			nxt1|=1<<cnt;
		}
		bit>>=1,cnt++;
	}
	ans=min(ans,dfs(step+1,nxt1,nxt2)+c[step]);
	return dp[step][sta1][sta2]=ans;
}
int main()
{
	while(scanf("%d%d%d",&s,&m,&n)&&s)
	{
		int sum=0,sta1=0,sta2=0,x;
		char ch;
		for(int i=1;i<=m;i++)
		{
			scanf("%d%c",&x,&ch),sum+=x;
			while(ch!='\n')
			{
				scanf("%d%c",&x,&ch);
				int bit=1<<(x-1);
				if(sta1&bit) sta2|=bit;
				sta1|=bit;
			}
		}
		for(int i=1;i<=n;i++)
		{
			scanf("%d%c",&c[i],&ch);
			sta[i]=0;
			while(ch!='\n')
				scanf("%d%c",&x,&ch),sta[i]|=1<<(x-1);
		}
		memset(dp,-1,sizeof(dp));
		printf("%d\n",dfs(1,sta1,sta2)+sum);
	}
}