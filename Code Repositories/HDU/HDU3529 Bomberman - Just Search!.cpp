#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+5;
int idx,ans,g[20][20],vis[35];
int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
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
		for(int i=d[id];i!=id;i=d[i])
			l[r[i]]=l[i],r[l[i]]=r[i];
	}
	void recover(int id)
	{
		for(int i=u[id];i!=id;i=u[i])
			l[r[i]]=r[l[i]]=i;
	}
	int h()
	{
		int ans=0;
		memset(vis,0,sizeof(vis));
		for(int i=r[0];i;i=r[i])
		{
			if(vis[i]) continue;
			ans++;
			for(int j=d[i];j!=i;j=d[j])
				for(int k=r[j];k!=j;k=r[k])
					vis[col[k]]=1;
		}
		return ans;
	}
	void dance(int step)
	{
		if(step+h()>=ans) return;
		if(!r[0])
		{	ans=step; return; }
		int id=r[0];
		for(int i=r[0];i;i=r[i])
			if(siz[i]<siz[id]) id=i;
		for(int i=d[id];i!=id;i=d[i])
		{
			remove(i);
			for(int j=r[i];j!=i;j=r[j]) remove(j);
			dance(step+1);
			for(int j=l[i];j!=i;j=l[j]) recover(j);
			recover(i);
		}
	}
}dlx;
int main()
{
	int n,m;
	char s[20][20];
	while(~scanf("%d%d",&n,&m))
	{
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%s",s[i]+1);
			for(int j=1;j<=m;j++)
				if(s[i][j]=='#') g[i][j]=++cnt;
		}
		idx=0,ans=n*m,dlx.build(n*m,cnt);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
			{
				if(s[i][j]!='.') continue;
				idx++;
				for(int d=0;d<4;d++)
				{
					int x=i,y=j;
					while(x>0&&y>0&&x<=n&&y<=m)
					{
						if(s[x][y]=='#')
							dlx.insert(idx,g[x][y]);
						if(s[x][y]!='.') break;
						x+=dx[d],y+=dy[d];
					}
				}
			}
		dlx.dance(0);
		printf("%d\n",ans);
	}
}