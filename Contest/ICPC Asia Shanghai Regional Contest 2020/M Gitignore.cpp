#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+5;
char s[maxn];
vector<int>e[maxn];
int tag[maxn],siz1[maxn],siz2[maxn],dp[maxn];
void dfs(int u)
{
	dp[u]=siz1[u]=siz2[u]=0;
	if(e[u].empty())
	{	siz1[u]=1,siz2[u]=dp[u]=tag[u]; return; }
	for(int v:e[u])
	{
		dfs(v),dp[u]+=dp[v];
		siz1[u]+=siz1[v],siz2[u]+=siz2[v];
	}
	if(u&&siz1[u]==siz2[u]) dp[u]=min(dp[u],1);
}
int main()
{
	int t,n,m;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		map<string,int>mp;
		int tot=0;
		for(int i=1;i<=n+m;i++)
		{
			scanf("%s",s);
			int len=strlen(s),las=0;
			string cur="";
			for(int j=0;j<len;j++)
			{
				if(s[j]=='/')
				{
					if(!mp[cur]) 
						mp[cur]=++tot,e[las].push_back(mp[cur]);
					las=mp[cur];
				}
				cur+=s[j];
			}
			if(!mp[cur]) 
				mp[cur]=++tot,e[las].push_back(mp[cur]);
			tag[mp[cur]]=i<=n;
		}
		dfs(0);
		printf("%d\n",dp[0]);
		for(int i=0;i<=tot;i++)
			e[i].clear(),tag[i]=0;
	}
}