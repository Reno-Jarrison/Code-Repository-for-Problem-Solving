#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int maxn=2e3+5;
struct node
{	int nxt[80],fail,end; }trie[maxn];
char pat[maxn],c[3];
int cnt,lenth,vis[maxn][105];
double p[80],dp[maxn][105];
void build(char *s)
{
	int len=strlen(s),u=0;
	for(int i=0;i<len;i++)
	{
		int v=s[i]-'0';
		if(!trie[u].nxt[v])
			trie[u].nxt[v]=++cnt;
		u=trie[u].nxt[v];
	}
	trie[u].end=1;
}
void getfail()
{
	queue<int>q;
	for(int i=0;i<80;i++)
		if(trie[0].nxt[i]) q.push(trie[0].nxt[i]);
	while(!q.empty())
	{
		int u=q.front(); q.pop();
		for(int i=0;i<80;i++)
		{
			int v=trie[u].nxt[i],f=trie[u].fail,fnxt=trie[f].nxt[i];
			if(v) trie[v].fail=fnxt,trie[v].end|=trie[fnxt].end,q.push(v);
			else trie[u].nxt[i]=fnxt;
		}
	}
}
double dfs(int u,int step)
{
	if(step==lenth) return 1.0;
	if(vis[u][step]) return dp[u][step];
	vis[u][step]=1;
	double ans=0;
	for(int i=0;i<80;i++)
	{
		int v=trie[u].nxt[i];
		if(!trie[v].end) ans+=dfs(v,step+1)*p[i];
	}
	return dp[u][step]=ans;
}
int main()
{
	int t,n,m,cases=0;
	scanf("%d",&t);
	while(t--)
	{
		memset(trie,0,sizeof(trie)),cnt=0;
		memset(vis,0,sizeof(vis));
		memset(p,0,sizeof(p));
		memset(dp,0,sizeof(dp));
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%s",pat),build(pat);
		scanf("%d",&m);
		for(int i=1;i<=m;i++)
			scanf("%s",c),scanf("%lf",&p[c[0]-'0']);
		scanf("%d",&lenth),getfail();
		printf("Case #%d: %.6lf\n",++cases,dfs(0,0));
	}
}