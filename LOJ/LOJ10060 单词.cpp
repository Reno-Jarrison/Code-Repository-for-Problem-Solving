#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int maxn=1e6+5;
struct node
{	int nxt[26],fail,end; }trie[maxn];
struct edge
{
	int to,nxt;
	edge(int to=0,int nxt=0):to(to),nxt(nxt){}
}e[maxn];
int head[maxn],cnt1,cnt2,idx[maxn];
char pat[maxn];
void init()
{	memset(head,-1,sizeof(head)),cnt2=0; }
void link(int u,int v)
{	e[cnt2]=edge(v,head[u]),head[u]=cnt2++; }
void build(int id,char *s)
{
	int len=strlen(s),u=0;
	for(int i=0;i<len;i++)
	{
		int v=s[i]-'a';
		if(!trie[u].nxt[v])
			trie[u].nxt[v]=++cnt1;
		u=trie[u].nxt[v],trie[u].end++;
	}
	idx[id]=u;
}
void getfail()
{
	queue<int>q;
	for(int i=0;i<26;i++)
		if(trie[0].nxt[i])
			q.push(trie[0].nxt[i]),link(0,trie[0].nxt[i]);
	while(!q.empty())
	{
		int u=q.front(); q.pop();
		for(int i=0;i<26;i++)
		{
			int v=trie[u].nxt[i],f=trie[u].fail;
			if(v) trie[v].fail=trie[f].nxt[i],link(trie[v].fail,v),q.push(v);
			else trie[u].nxt[i]=trie[f].nxt[i];
		}
	}
}
void dfs(int u,int f)
{
	for(int i=head[u];~i;i=e[i].nxt)
	{
		int v=e[i].to;
		if(v!=f) dfs(v,u),trie[u].end+=trie[v].end;
	}
}
int main()
{
	init();
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%s",pat),build(i,pat);
	getfail(),dfs(0,0);
	for(int i=1;i<=n;i++)
		printf("%d\n",trie[idx[i]].end);
}