#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
struct node
{
	int pos,sta;
	node(int pos,int sta):pos(pos),sta(sta){}
};
int n,dist[20][1<<16],path[20][1<<16][4],ans;
bool e[20][20];
int update(int tmp,int x,int y)
{	return (tmp^(1<<(x-1)))|(1<<(y-1)); }
bool bfs(node s,int end)
{
	queue<node>q;
	q.push(s),dist[s.pos][s.sta]=0;
	while(!q.empty())
	{
		node tmp=q.front(); q.pop();
		int pos=tmp.pos,sta=tmp.sta,d=dist[pos][sta];
		if(pos==end) { ans=sta; return true; }
		for(int i=1;i<=n;i++) if(sta&(1<<(i-1)))
			for(int j=1;j<=n;j++) 
				if(e[i][j]&&!(sta&(1<<(j-1))))
				{
					int np=i==pos?j:pos;
					int ns=update(sta,i,j);
					if(dist[np][ns]==-1)
					{
						dist[np][ns]=d+1;
						path[np][ns][0]=pos;
						path[np][ns][1]=sta;
						path[np][ns][2]=i;
						path[np][ns][3]=j;
						q.push(node(np,ns));
					}
				}
	}
	return false;
}
void dfs(int pt,int tmp,int s,int sta)
{
	if(pt==s&&tmp==sta) return;
	dfs(path[pt][tmp][0],path[pt][tmp][1],s,sta);
	printf("%d %d\n",path[pt][tmp][2],path[pt][tmp][3]);
}
int main()
{
	int T,m,s,t,x,u,v,sta,ks=0;
	scanf("%d",&T);
	while(T--)
	{
		memset(e,0,sizeof(e));
		memset(dist,-1,sizeof(dist));
		scanf("%d%d%d%d",&n,&m,&s,&t);
		sta=1<<(s-1),ans=-1;
		for(int i=1;i<=m;i++)
			scanf("%d",&x),sta|=1<<(x-1);
		for(int i=1;i<n;i++)
			scanf("%d%d",&u,&v),e[u][v]=e[v][u]=true;
		bool ok=bfs(node(s,sta),t);
		printf("Case %d: %d\n",++ks,dist[t][ans]);
		if(ok) dfs(t,ans,s,sta);
		puts("");
	}
}