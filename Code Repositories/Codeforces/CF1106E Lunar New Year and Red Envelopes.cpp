#include<bits/stdc++.h> 
#define maxn 100005
using namespace std;
struct node
{
	int s,t,d;
	long long w;
	bool operator <(const node &n) const
	{
		if(n.w==w)
			return d<n.d;
		return w<n.w;
	}
}p[maxn];
long long dp[maxn][205],minn=LLONG_MAX;
bool cmp(node a,node b) {return a.s<b.s;}
priority_queue<node>q;
void update(long long &a,long long b)
{
	if(b==-1)
		return;
	a=(a==-1?b:min(a,b));
}
int main()
{
	int n,m,k,pt=0;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<k;i++)
		scanf("%d%d%d%lld",&p[i].s,&p[i].t,&p[i].d,&p[i].w);
	sort(p,p+k,cmp);
	memset(dp,-1,sizeof(dp));
	dp[1][0]=0;
	for(int t=1;t<=n;t++)
	{
		while(p[pt].s<=t&&pt<k)
			q.push(p[pt++]);
		while(!q.empty()&&q.top().t<t)
			q.pop();
		if(q.empty())
			for(int i=0;i<=m;i++)
				update(dp[t+1][i],dp[t][i]);
		else
		{
			node nnode=q.top();
			for(int i=0;i<=m;i++)
			{
				if(dp[t][i]==-1)
					continue;
				update(dp[min(nnode.d+1,n+1)][i],dp[t][i]+nnode.w);
				if(i!=m)
					update(dp[min(t+1,n+1)][i+1],dp[t][i]);
			}
		}
	}
	for(int i=0;i<=m;i++)
		update(minn,dp[n+1][i]);
	printf("%lld",minn);
} 
