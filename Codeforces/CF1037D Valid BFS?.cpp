#include<cstdio>
#include<vector>
#include<queue>
#define ll long long
using namespace std;
const int maxn=2e5+5;
int d[maxn];
bool flag[maxn],tag[maxn];
vector<int>e[maxn];
int t,idx[maxn],f[maxn];
struct node
{	
	int rt,dep; 
	node(int rt,int dep):rt(rt),dep(dep){}
};
void link(int u,int v)
{
	e[u].push_back(v);
	e[v].push_back(u);
}
void bfs()
{
	queue<node>q;
	d[1]=1,q.push({1,1});
	while(!q.empty())
	{
		node u=q.front(); q.pop();
		for(int v:e[u.rt]) if(!d[v]) 
			d[v]=u.dep+1,f[v]=u.rt,q.push({v,d[v]});
	}
}
int main()
{
	int n,u,v,x,las=0,ok=1;
	scanf("%d",&n);
	for(int i=1;i<n;i++)
		scanf("%d%d",&u,&v),link(u,v);
	bfs();
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		if(x>n||x<1||d[x]<d[las]||flag[x]||idx[f[x]]<idx[f[las]]) ok=0;
		idx[x]=++t,flag[x]=true,las=x;
	}
	puts(ok?"Yes":"No");
}