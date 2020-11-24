#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
int n,idx,stk[maxn],ans[55];
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
		if(!r[0]||r[0]>2*n) return step;
		int id=r[0];
		for(int i=r[0];i;i=r[i])
			if(i<=2*n&&siz[i]<siz[id]) id=i;
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
struct node
{
	int r,c;
	node(int r=0,int c=0):r(r),c(c){}
}p[maxn];
void update(int r,int c)
{
	p[++idx]=node(r,c);
	dlx.insert(idx,r);
	dlx.insert(idx,n+c);
	dlx.insert(idx,n*2+r+c-1);
	dlx.insert(idx,n*4-1+r-c+n);
}
int main()
{
	int x;
	while(~scanf("%d",&n))
	{
		idx=0,dlx.build(n*n,6*n-2);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&x);
			if(x) update(i,x);
			else for(int j=1;j<=n;j++)
				update(i,j);
		}
		int step=dlx.dance(0);
		for(int i=1;i<=step;i++)
			ans[p[stk[i]].r]=p[stk[i]].c;
		for(int i=1;i<=n;i++)
			printf("%d%c",ans[i],i==n?'\n':' ');
	}
}