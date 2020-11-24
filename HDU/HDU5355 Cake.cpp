#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e5+5;
int vis[maxn],idx[maxn];
vector<int>vec[15];
bool dfs(int step,int pos,int sum,int tot,int res)
{
	if(!step) return true;
	for(int i=min(pos,tot-sum);i;i--)
	{
		if(vis[i]) continue;
		idx[i]=step,vis[i]=true;
		if(sum+i==tot&&dfs(step-1,res,0,tot,res)) return true;
		if(sum+i<tot&&dfs(step,pos-1,sum+i,tot,res)) return true;
		vis[i]=false;
	}
	return false;
}
int main()
{
	int t,n,m;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		ll sum=1LL*n*(n+1)/2,tot=sum/m;
		if(sum%m||tot<n)
		{	puts("NO"); continue; }
		for(int i=1;i<=m;i++) vec[i].clear();
		int res=n%(2*m);
		if(res) res=min(n,res+2*m);
		while(n>res)
		{
			for(int i=1;i<=m;i++)
				vec[i].push_back(n-2*m+i),vec[i].push_back(n-i+1);
			tot-=2*n-2*m+1,n-=m*2;
		}
		for(int i=1;i<=res;i++) vis[i]=0;
		if(res&&!dfs(m,res,0,tot,res)) puts("NO");
		else
		{
			puts("YES");
			for(int i=1;i<=res;i++)
				vec[idx[i]].push_back(i);
			for(int i=1;i<=m;i++)
			{
				printf("%d",(int)vec[i].size());
				for(int x:vec[i]) printf(" %d",x);
				puts("");
			}
		}
	}
}