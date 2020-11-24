#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int maxn=5e6+5,inf=0x3f3f3f3f;
int dist[maxn],cost[105];
bool inq[maxn];
char s[105][2][25];
struct node
{
	int u,w;
	node(int u,int w):u(u),w(w){}
};
int spfa(int n,int m)
{
	memset(dist,inf,sizeof(dist));
	int beg=(1<<n)-1;
	queue<int>q;
	dist[beg]=0,q.push(beg),inq[beg]=true;
	while(!q.empty())
	{
		int u=q.front(),tmp=u;
		q.pop(),inq[u]=false;
		char check[25];
		for(int i=0;i<n;i++)
			check[i]=tmp&1,tmp>>=1;
		for(int i=1;i<=m;i++)
		{
			bool exi=true;
			for(int j=0;j<n;j++)
				if(s[i][0][j]=='+'&&check[j]==0) { exi=false; break; }
				else if(s[i][0][j]=='-'&&check[j]==1) { exi=false; break; }
			if(!exi) continue;
			int v=0;
			for(int j=0;j<n;j++)
				if(s[i][1][j]=='+') v+=1<<j;
				else if(s[i][1][j]=='0') v+=check[j]<<j;
			if(dist[v]>dist[u]+cost[i])
				dist[v]=dist[u]+cost[i],!inq[v]?q.push(v),inq[v]=true:false;
		}
		
	}
	return dist[0];
}
int main()
{
	int n,m,cases=0;
	while(scanf("%d%d",&n,&m)&&n&&m)
	{
		for(int i=1;i<=m;i++)
			scanf("%d%s%s",&cost[i],s[i][0],s[i][1]);
		int ans=spfa(n,m);
		printf("Product %d\n",++cases);
		if(ans==inf) printf("Bugs cannot be fixed.\n");
		else printf("Fastest sequence takes %d seconds.\n",ans);
		printf("\n");
	}
}