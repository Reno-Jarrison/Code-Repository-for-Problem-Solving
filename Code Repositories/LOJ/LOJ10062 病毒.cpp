#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int maxn=3e4+5;
struct node
{	int nxt[2],fail,vis,end; }trie[maxn];
int cnt,vis[maxn],ins[maxn];
char pat[maxn];
void build(char *s)
{
	int len=strlen(s),u=0;
	for(int i=0;i<len;i++)
	{
		int v=s[i]-'0';
		if(!trie[u].nxt[v]) trie[u].nxt[v]=++cnt;
		u=trie[u].nxt[v];
	}
	trie[u].end=1;
}
void getfail()
{
	queue<int>q;
	if(trie[0].nxt[0]) q.push(trie[0].nxt[0]);
	if(trie[0].nxt[1]) q.push(trie[0].nxt[1]);
	while(!q.empty())
	{
		int u=q.front(); q.pop();
		for(int i=0;i<2;i++)
		{
			int v=trie[u].nxt[i],f=trie[u].fail,fnxt=trie[f].nxt[i];
			if(v) trie[v].fail=fnxt,trie[v].end|=trie[fnxt].end,q.push(v);
			else trie[u].nxt[i]=trie[f].nxt[i];
		}
	}
}
bool dfs(int u)
{
	if(ins[u]) return true;
	if(vis[u]||trie[u].end) return false;
	ins[u]=vis[u]=1;
	for(int i=0;i<2;i++)
		if(trie[u].nxt[i]&&dfs(trie[u].nxt[i])) return true;
	ins[u]=0;
	return false;
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%s",pat),build(pat);
	getfail(),printf(dfs(0)?"TAK":"NIE");
}