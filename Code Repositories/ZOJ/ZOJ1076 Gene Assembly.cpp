#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+5;
struct node
{	int l,r,id; }p[maxn];
bool operator <(const node& a,const node& b)
{	return a.r<b.r; }
int dp[maxn],pre[maxn];
void dfs(int x)
{
	if(!x) return;
	dfs(pre[x]);
	printf("%d ",p[x].id);
}
int main()
{
	int n;
	while(scanf("%d",&n)&&n)
	{
		for(int i=1;i<=n;i++)
			scanf("%d%d",&p[i].l,&p[i].r),p[i].id=i,dp[i]=0;
		sort(p+1,p+n+1);
		int mxv=0,id=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<i&&p[j].r<p[i].l;j++)
				if(dp[j]+1>dp[i]) 
					dp[i]=dp[j]+1,pre[i]=j;
			if(dp[i]>mxv) mxv=dp[i],id=i;
		}
		dfs(pre[id]);
		printf("%d\n",p[id].id);
	}
}