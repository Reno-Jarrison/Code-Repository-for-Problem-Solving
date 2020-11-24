#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=305*20;
int stk[maxn];
struct DLX
{
	int n,m,tot,head[maxn],siz[maxn];
	int l[maxn],r[maxn],u[maxn],d[maxn];
	int row[maxn],col[maxn];
	void build(int x,int y)
	{
		n=x,m=y;
		for(int i=0;i<=y;i++)
			l[i]=i-1,r[i]=i+1,u[i]=d[i]=i;
		l[0]=y,r[y]=0,tot=y;
		fill(head+1,head+x+1,0);
		fill(siz,siz+y+1,0);
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
			stk[step]=row[i];
			for(int j=r[i];j!=i;j=r[j]) remove(col[j]);
			int ans=dance(step+1);
			if(ans) return ans;
			for(int j=l[i];j!=i;j=l[j]) recover(col[j]);
		}
		recover(id);
		return 0;
	}
}dlx;
int main()
{
	int n,m,x;
	while(~scanf("%d%d",&n,&m))
	{
		dlx.build(n,m);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
			{
				scanf("%d",&x);
				if(x) dlx.insert(i,j);
			}
		puts(dlx.dance(0)?"Yes, I found it":"It is impossible");
	}
}