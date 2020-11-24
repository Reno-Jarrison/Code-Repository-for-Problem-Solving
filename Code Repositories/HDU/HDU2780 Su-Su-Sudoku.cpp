#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
int ans[10][10],stk[maxn],idx;
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
			if(ans!=-1) return ans;
			for(int j=l[i];j!=i;j=l[j]) recover(col[j]);
		}
		recover(id);
		return -1;
	}
}dlx;
struct node
{
	int r,c,x;
	node(int r=0,int c=0,int x=0):r(r),c(c),x(x){}
}p[maxn];
int id(int r,int c)
{	return (r-1)/3*3+(c-1)/3+1; }
void update(int r,int c,int x)
{
	p[++idx]=node(r,c,x);
	dlx.insert(idx,(r-1)*9+c);
	dlx.insert(idx,81+(r-1)*9+x);
	dlx.insert(idx,81*2+(c-1)*9+x);
	dlx.insert(idx,81*3+(id(r,c)-1)*9+x);
}
int main()
{
	char s[15];
	int t,fst=1;
	scanf("%d",&t);
	while(t--)
	{
		idx=0,dlx.build(729,324);
		for(int i=1;i<=9;i++)
		{
			scanf("%s",s+1);
			for(int j=1;j<=9;j++)
			{
				if(s[j]=='0') for(int k=1;k<=9;k++)
					update(i,j,k);
				else update(i,j,s[j]-'0');
			}
		}
		fst?fst=0:puts("");
		int step=dlx.dance(0);
		if(step==-1) 
		{	puts("Could not complete this grid."); continue; }
		for(int i=1;i<=step;i++)
			ans[p[stk[i]].r][p[stk[i]].c]=p[stk[i]].x;
		for(int i=1;i<=9;i++)
		{
			for(int j=1;j<=9;j++)
				printf("%d",ans[i][j]);
			puts("");
		}
	}
}