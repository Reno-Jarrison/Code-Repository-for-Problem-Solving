#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5,inf=0x3f3f3f3f;
vector<int>e[maxn],id[maxn],node[2][maxn],bkt[maxn];
int mxd,k[maxn],feq[maxn];
pair<int,int>pre[maxn];
bool dp[maxn],ans[maxn];
void dfs1(int u,int dep)
{
	id[dep].push_back(u);
	mxd=max(mxd,dep);
	int tag=e[u].empty();
	node[tag][dep].push_back(u);
	for(int v:e[u])
		dfs1(v,dep+1);
}
void getans(int x)
{
	if(!x) return;
	int num=pre[x].first,val=pre[x].second;
	for(int i=0;i<num;i++)
		for(int j:id[bkt[val][i]])
			ans[j]=1;
	getans(x-num*val);
}
int main()
{
	int n,x,p;
	scanf("%d%d",&n,&x);	
	for(int i=2;i<=n;i++)
		scanf("%d",&p),e[p].push_back(i);
	dfs1(1,1);
	for(int i=1;i<=n;i++)
		bkt[id[i].size()].push_back(i),feq[id[i].size()]++;
	dp[0]=true;
	for(int i=1;i<=n;i++) if(feq[i])
	{
		for(int j=0;j<i;j++)
			k[j]=dp[j]?0:-inf;
		for(int j=i;j<=x;j++)
		{
			k[j]=dp[j]?0:k[j-i]+1;
			if(k[j]>=0&&k[j]<=feq[i])
			{
				dp[j]=true;
				if(k[j]>0) pre[j]=make_pair(k[j],i);
			}
		}
	}
	if(dp[x]) getans(x);
	else
	{
		int cnt=x,tot=n,tag;
		for(int i=1;i<=mxd;i++)
		{
			tag=(int)node[0][i].size()<=cnt;
			for(int j:node[0][i])
				ans[j]=tag,cnt-=tag,tot--;
			for(int j:node[1][i])
			{
				if((tag&&cnt>0)||tot-cnt==0) 
					ans[j]=1,cnt--;
				tot--;
			}
		}
	}
	printf("%d\n",mxd+!dp[x]);
	for(int i=1;i<=n;i++)
		putchar(ans[i]?'a':'b');
}