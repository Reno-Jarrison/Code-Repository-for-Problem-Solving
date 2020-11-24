#include<cstdio>
#include<vector>
using namespace std;
const int maxn=8e3+5;
vector<int>e[maxn<<1];
bool flag[maxn<<1];
int s[maxn<<1],tp;
void link(int u,int v)
{
	e[u].push_back(v^1);
	e[v].push_back(u^1);
}
bool dfs(int u)
{
	if(flag[u^1]) return false;
	if(flag[u]) return true;
	flag[u]=true;
	s[++tp]=u;
	for(int i=0;i<(int)e[u].size();i++)
		if(!dfs(e[u][i])) return false;
	return true;
}
bool twosat(int n)
{
	for(int i=2;i<=n<<1;i+=2)
		if(!flag[i]&&!flag[i+1])
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
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
		scanf("%d%d",&u,&v),link(u+1,v+1);
	if(!twosat(n)) printf("NIE");
	else
	{
		for(int i=2;i<=n<<1;i+=2)
			printf("%d\n",flag[i]?i-1:i);
	}
}