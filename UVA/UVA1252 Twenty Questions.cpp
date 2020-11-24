#include<bits/stdc++.h>
using namespace std;
int cnt[1<<11][1<<11],dp[1<<11][1<<11],n,m;
int dfs(int s1,int s2)
{
	if(cnt[s1][s2]==1) return 0;
	if(~dp[s1][s2]) return dp[s1][s2];
	int ans=0x3f3f3f3f;
	for(int i=0;i<n;i++)
	{
		int bit=1<<i,ns1=s1|bit,ns2=s2|bit;
		if(s1&bit||!cnt[ns1][s2]||!cnt[ns1][ns2]) continue;
		ans=min(ans,max(dfs(ns1,s2),dfs(ns1,ns2))+1);
	}
	return dp[s1][s2]=ans;
}
int main()
{
	char s[15];
	while(scanf("%d%d",&n,&m)&&n)
	{
		memset(cnt,0,sizeof(cnt));
		for(int i=1;i<=m;i++)
		{
			int sta=0;
			scanf("%s",s);
			for(int j=0;j<n;j++) 
				if(s[j]=='1') sta|=1<<j;
			for(int j=0;j<(1<<n);j++)
				cnt[j][j&sta]++;
		}
		memset(dp,-1,sizeof(dp));
		printf("%d\n",dfs(0,0));
	}
}