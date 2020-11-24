#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<queue>
using namespace std;
const int maxn=55;
const double eps=1e-3;
double dist[maxn];
int inq[maxn],tot[maxn];
int head[maxn],cnt;
struct edge
{
	int to,nxt; double w;
}e[maxn*maxn*2];
void init()
{
	for(int i=0;i<maxn*maxn*2;i++) e[i].nxt=-1;
	memset(head,-1,sizeof(head)),cnt=0;
}
void addedge(int u,int v,double w)
{
	e[cnt].to=v;
	e[cnt].w=w;
	e[cnt].nxt=head[u];
	head[u]=cnt++;
}
bool negcycle(int n)
{
	memset(inq,0,sizeof(inq));
	memset(tot,0,sizeof(tot));
	queue<int>q;
	for(int i=1;i<=n;i++)
		dist[i]=0,q.push(i),inq[i]=true;
	while(!q.empty())
	{
		int u=q.front();
		q.pop(); inq[u]=false;
		for(int i=head[u];~i;i=e[i].nxt)
		{
			int v=e[i].to; double w=e[i].w;
			if(dist[v]>dist[u]+w)
			{
				dist[v]=dist[u]+w;
				if(inq[v]) continue;
				q.push(v),inq[v]=true;
				if(++tot[v]>n) return true;
			}

		}
	}
	return false;
}
bool check(int n,double x)
{
	for(int i=0;i<cnt;i++) e[i].w-=x;
	bool ans=negcycle(n);
	for(int i=0;i<cnt;i++) e[i].w+=x;
	return ans;
}
int main()
{
	int t,n,m,u,v,w,cases=0;
	scanf("%d",&t);
	while(t--)
	{
		double maxn=0,l,r,mid;
		scanf("%d%d",&n,&m);
		init();
		for(int i=1;i<=m;i++)
		{
			scanf("%d%d%d",&u,&v,&w);
			addedge(u,v,(double)w);
			maxn=max(maxn,(double)w);
		}
		l=0,r=maxn;
		printf("Case #%d: ",++cases);
		if(!check(n,maxn+1)) { printf("No cycle found.\n"); continue; }
		while(r-l>eps)
		{
			mid=(l+r)/2;
			if(check(n,mid)) r=mid;
			else l=mid;
		}
		printf("%.2lf\n",l);
	}
}