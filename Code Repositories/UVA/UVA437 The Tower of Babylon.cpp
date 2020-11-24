#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
#include<queue>
#include<iostream>
using namespace std;
int p[35][3],dp[100],ind[100],rk[100],cnt;
vector<int>e[100];
void link(int x,int y,int n)
{
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
		{
			int ax=p[x][(i+1)%3],ay=p[x][(i+2)%3];
			int bx=p[y][(j+1)%3],by=p[y][(j+2)%3];
			if(ax>ay) swap(ax,ay);
			if(bx>by) swap(bx,by);
			if(ax>bx&&ay>by) 
			{
				int u=x+i*n,v=y+j*n;
				ind[v]++,e[u].push_back(v);
			}
		}
}
void init()
{	
	cnt=0,memset(ind,0,sizeof(ind)); 
	for(int i=0;i<100;i++) e[i].clear();
}
void topsort(int n)
{
	queue<int>q;
	for(int i=0;i<n;i++)
		if(!ind[i]) q.push(i);
	while(!q.empty())
	{
		int u=q.front(); q.pop();
		rk[++cnt]=u;
		for(int i=0;i<(int)e[u].size();++i)
		{
			int v=e[u][i];
			if(!--ind[v]) q.push(v);
		}
	}
}
int main()
{
	int n,n3,cases=0;
	while(~scanf("%d",&n)&&n)
	{
		init(),n3=n*3;
		for(int i=0;i<n;i++)
			for(int j=0;j<3;j++)
				scanf("%d",&p[i][j]),dp[i+j*n]=p[i][j];
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				link(i,j,n);
		topsort(n3);
		for(int i=1;i<=n3;i++)
		{
			int u=rk[i];
			for(int i=0;i<(int)e[u].size();++i)
			{
				int v=e[u][i];
				dp[v]=max(dp[v],dp[u]+p[v%n][v/n]);
			}
		}
		int ans=0;
		for(int i=0;i<n3;i++)
			ans=max(ans,dp[i]);
		printf("Case %d: maximum height = %d\n",++cases,ans);
	}
}
