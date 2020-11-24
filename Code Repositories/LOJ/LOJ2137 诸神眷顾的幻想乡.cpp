#include<cstdio>
#include<cstring>
#include<vector>
#define ll long long
using namespace std;
const int maxn=1e5+5;
struct node
{	int nxt[10],len,fat; }trie[maxn*20];
int cnt=1,c,a[maxn],d[maxn];
vector<int>e[maxn];
int build(int x,int p)
{
	int np=++cnt;
	trie[np].len=trie[p].len+1;
	while(p&&!trie[p].nxt[x])
		trie[p].nxt[x]=np,p=trie[p].fat;
	if(!p) { trie[np].fat=1; return np; }
	int q=trie[p].nxt[x];
	if(trie[q].len==trie[p].len+1)
		trie[np].fat=q;
	else
	{
		int nq=++cnt;
		trie[nq]=trie[q];
		trie[nq].len=trie[p].len+1;
		trie[np].fat=trie[q].fat=nq;
		while(p&&trie[p].nxt[x]==q)
			trie[p].nxt[x]=nq,p=trie[p].fat;
	}
	return np;
}
void dfs(int u,int f,int pt)
{
	pt=build(a[u],pt);
	for(int i=0;i<(int)e[u].size();i++)
	{
		int v=e[u][i];
		if(v!=f) dfs(v,u,pt);
	}
}
int main()
{
	int n,c,u,v;
	scanf("%d%d",&n,&c);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<n;i++)
	{
		scanf("%d%d",&u,&v);
		d[u]++,d[v]++;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	for(int i=1;i<=n;i++)
		if(d[i]==1) dfs(i,0,1);
	ll ans=0;
	for(int i=1;i<=cnt;i++)
		ans+=trie[i].len-trie[trie[i].fat].len;
	printf("%lld\n",ans);
}