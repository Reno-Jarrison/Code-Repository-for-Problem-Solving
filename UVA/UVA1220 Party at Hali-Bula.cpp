#include<bits/stdc++.h>
using namespace std;
const int maxn=205;
vector<int>e[maxn];
int dp[maxn][2],tag[maxn][2];
void dfs(int u)
{
	dp[u][0]=dp[u][1]=tag[u][0]=tag[u][1]=0;
	for(int v:e[u])
	{
		dfs(v);
		dp[u][0]+=max(dp[v][0],dp[v][1]);
		if(dp[v][0]>dp[v][1]) tag[u][0]|=tag[v][0];
		if(dp[v][0]<dp[v][1]) tag[u][0]|=tag[v][1];
		tag[u][0]|=(dp[v][0]==dp[v][1]);
		dp[u][1]+=dp[v][0];
		tag[u][1]|=tag[v][0];
	}
	dp[u][1]++;
}
int main()
{
	int n;
	while(cin>>n&&n)
	{
		map<string,int>mp;
		string u,v;
		cin>>u,mp[u]=1;
		int idx=1,ok=0,ans;
		for(int i=1;i<=n;i++) e[i].clear();
		for(int i=1;i<n;i++)
		{
			cin>>u>>v;
			if(!mp[u]) mp[u]=++idx;
			if(!mp[v]) mp[v]=++idx;
			e[mp[v]].push_back(mp[u]);
		}
		dfs(1);
		if(dp[1][0]>dp[1][1]) ans=dp[1][0],ok=tag[1][0];
		else if(dp[1][0]<dp[1][1]) ans=dp[1][1],ok=tag[1][1];
		else ans=dp[1][0],ok=1;
		printf("%d %s\n",ans,!ok?"Yes":"No");
	}
}