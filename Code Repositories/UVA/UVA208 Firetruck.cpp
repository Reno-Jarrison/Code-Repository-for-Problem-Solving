#include<cstdio>
#include<set>
using namespace std;
set<int>s[25];
int f[25],ans[25],flag[25],cnt;
int find(int x)
{	return f[x]==x?x:f[x]=find(f[x]); }
void link(int u,int v)
{
	s[u].insert(v);
	s[v].insert(u);
	int fu=find(u),fv=find(v);
	if(fu!=fv) f[fu]=fv;
}
void dfs(int u,int t,int step)
{
	if(u==t)
	{
		for(int i=0;i<step;i++)
			printf("%d%c",ans[i],i==step-1?'\n':' ');
		cnt++;
	}
	for(int v:s[u]) if(!flag[v])
		flag[v]=1,ans[step]=v,dfs(v,t,step+1),flag[v]=0;
}
int main()
{
	int n,u,v,ks=0;
	flag[1]=ans[0]=1;
	while(~scanf("%d",&n))
	{
		for(int i=1;i<=20;i++) f[i]=i,s[i].clear();
		while(scanf("%d%d",&u,&v)&&u&&v) link(u,v);
		cnt=0,printf("CASE %d:\n",++ks);
		if(find(1)==find(n)) dfs(1,n,1);
		printf("There are %d routes from the firestation to streetcorner %d.\n",cnt,n);
	}
}