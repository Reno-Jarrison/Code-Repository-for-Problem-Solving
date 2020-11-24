#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=5e6;
int idx,stk[maxn],ans[20][20];
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
struct node
{
	int r,c,x;
	node(int r=0,int c=0,int x=0):r(r),c(c),x(x){}
}p[maxn];
int id(int r,int c)
{	return (r-1)/4*4+(c-1)/4+1; }
void update(int r,int c,int x)
{
	p[++idx]=node(r,c,x);
	dlx.insert(idx,(r-1)*16+c);
	dlx.insert(idx,256+(r-1)*16+x);
	dlx.insert(idx,256*2+(c-1)*16+x);
	dlx.insert(idx,256*3+(id(r,c)-1)*16+x);
}
int main()
{
	char s[20];
	while(1)
	{
		idx=0,dlx.build(4096,1024);
		for(int i=1;i<=16;i++)
		{
			if(scanf("%s",s+1)==-1)
				return 0;
			for(int j=1;j<=16;j++)
			{
				if(s[j]!='-') update(i,j,s[j]-'A'+1);
				else for(int k=1;k<=16;k++)
					update(i,j,k);
			}
		}
		int step=dlx.dance(0);
		for(int i=1;i<=step;i++)
			ans[p[stk[i]].r][p[stk[i]].c]=p[stk[i]].x;
		for(int i=1;i<=16;i++)
		{
			for(int j=1;j<=16;j++)
				printf("%c",'A'+ans[i][j]-1);
			puts("");
		}
		puts("");
	}
}
