#include<bits/stdc++.h>
using namespace std;
const int maxn=505*905,inf=0x3f3f3f3f;
struct DLX
{
	int n,m,tot,head[maxn],siz[maxn];
	int u[maxn],d[maxn],l[maxn],r[maxn];
	int row[maxn],col[maxn],ans;
	void build(int x,int y)
	{
		n=x,m=y,ans=inf;
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
	void dance(int step)
	{
		if(!r[0]) 
		{	ans=min(ans,step); return; }
		int id=r[0];
		for(int i=r[0];i;i=r[i])
			if(siz[i]<siz[id]) id=i;
		remove(id);
		for(int i=d[id];i!=id;i=d[i])
		{
			for(int j=r[i];j!=i;j=r[j]) remove(col[j]);
			dance(step+1);
			for(int j=l[i];j!=i;j=l[j]) recover(col[j]);
		}
		recover(id);
	}
}dlx;
int main()
{
	int t,n,m,p,x1,x2,y1,y2;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&n,&m,&p);
		dlx.build(p,n*m);
		for(int i=1;i<=p;i++)
		{
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			for(int j=x1+1;j<=x2;j++)
				for(int k=y1+1;k<=y2;k++)
					dlx.insert(i,(j-1)*m+k);
		}
		dlx.dance(0);
		if(dlx.ans==inf) dlx.ans=-1;
		printf("%d\n",dlx.ans);
	}
}