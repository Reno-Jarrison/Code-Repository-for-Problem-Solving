#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
set<int>e[65];
struct node
{
	int id,l,r;
	node(int id=0,int l=0,int r=0):id(id),l(l),r(r){}
}p[1500];
int stk[maxn],ans[maxn][2];
struct DLX
{
	int tot,head[maxn],siz[maxn];
	int l[maxn],r[maxn],u[maxn],d[maxn];
	int row[maxn],col[maxn];
	void build(int x,int y)
	{
		for(int i=0;i<=y;i++)
			l[i]=i-1,r[i]=i+1,u[i]=d[i]=i;
		l[0]=y,r[y]=0,tot=y;
		fill(head+1,head+x+1,0);
		fill(siz+1,siz+y+1,0);
	}
	void insert(int x,int y)
	{
		row[++tot]=x,col[tot]=y,siz[y]++;
		u[tot]=y,d[tot]=d[y],u[d[y]]=tot,d[y]=tot;
		if(!head[x]) head[x]=l[tot]=r[tot]=tot;
		else
		{
			l[tot]=head[x],r[tot]=r[head[x]];
			l[r[head[x]]]=tot,r[head[x]]=tot;
		}
	}
	void remove(int id)
	{
		l[r[id]]=l[id],r[l[id]]=r[id];
		for(int i=d[id];i!=id;i=d[i])
			for(int j=r[i];j!=i;j=r[j])
				u[d[j]]=u[j],d[u[j]]=d[j],siz[col[j]]--;
	}
	void recover(int id)
	{
		for(int i=u[id];i!=id;i=u[i])
			for(int j=l[i];j!=i;j=l[j])
				u[d[j]]=d[u[j]]=j,siz[col[j]]++;
		l[r[id]]=r[l[id]]=id;
	}
	int dance(int step)
	{
		if(!r[0]) return step;
		int id=r[0];
		for(int i=r[0];i;i=r[i])
			if(siz[i]<siz[id]) id=i;
		remove(id);
		for(int i=d[id];i!=id;i=d[i])
		{
			stk[step+1]=row[i];
			for(int j=r[i];j!=i;j=r[j]) remove(col[j]);
			int ans=dance(step+1);
			if(ans) return ans;
			for(int j=l[i];j!=i;j=l[j]) recover(col[j]);
		}
		recover(id);
		return 0;
	}
}dlx;
void link(int u,int v)
{	e[u].insert(v),e[v].insert(u); }
int main()
{
	int n,m,d,u,v,l,r;
	while(~scanf("%d%d%d",&n,&m,&d))
	{
		for(int i=1;i<=n;i++)
			e[i].clear(),e[i].insert(i);
		dlx.build(n*20,n*(d+1));
		for(int i=1;i<=m;i++)
			scanf("%d%d",&u,&v),link(u,v);
		int idx=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d",&l,&r);
			p[++idx]=node(i,0,0);
			dlx.insert(idx,n*d+i);
			for(int j=l;j<=r;j++)
				for(int k=j;k<=r;k++)
				{
					p[++idx]=node(i,j,k);
					dlx.insert(idx,n*d+i);
					for(int it=j;it<=k;it++)
						for(int x:e[i]) dlx.insert(idx,(it-1)*n+x);
				}
		}
		int step=dlx.dance(0);
		if(!step) puts("No solution");
		else
		{
			for(int i=1;i<=step;i++)
			{
				node cur=p[stk[i]];
				ans[cur.id][0]=cur.l;
				ans[cur.id][1]=cur.r;
			}
			for(int i=1;i<=n;i++)
				printf("%d %d\n",ans[i][0],ans[i][1]);
		}
		puts("");
	}
}