#include<cstdio>
#include<cstring>
#include<vector>
#include<string>
using namespace std;
const int maxn=1e5+5;
int a[maxn],s[maxn<<1],tp;
bool flag[maxn<<1];
vector<int>e[maxn<<1];
void link(int u,int a,int v,int b)
{
	int x=u*2+a,y=v*2+b;
	e[x].push_back(y^1);
	e[y].push_back(x^1);
}
bool dfs(int u)
{
	if(flag[u^1]) return false;
	if(flag[u]) return true;
	flag[s[++tp]=u]=true;
	for(int i=0;i<(int)e[u].size();i++)
		if(!dfs(e[u][i])) return false;
	return true;
}
bool twosat(int n)
{
	for(int i=2;i<=n<<1;i+=2)
		if(!flag[i]&&!flag[i|1])
		{
			tp=0;
			if(dfs(i)) continue;
			while(tp) flag[s[tp--]]=false;
			if(!dfs(i|1)) return false;
		}
	return true;
}
int main()
{
	int n,m,u,v;
	while(scanf("%d%d",&n,&m)&&n&&m)
	{
		int sum=0;
		memset(flag,0,sizeof(flag));
		for(int i=2;i<=n<<1;i++) e[i].clear();
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]),sum+=a[i];
		for(int i=1;i<=m;i++)
		{
			scanf("%d%d",&u,&v);
			bool tag1=a[u]*n>=sum,tag2=a[v]*n>=sum;
			link(u,0,v,0);
			if(tag1==tag2) link(u,1,v,1);
		}
		if(!twosat(n))
		{	printf("No solution.\n"); continue; }
		for(int i=1;i<=n;i++)
			printf("%c\n",flag[i<<1]?'C':a[i]*n>=sum?'A':'B');
	}
}