#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int maxn=1e5+5,maxm=1e7+5;
struct node
{	int nxt[4],fail,vis; }trie[maxn<<2];
int idx[maxn],fat[maxn<<2],ans[maxn],cnt;
char pat[maxn],txt[maxm];
int getpos(char x)
{
	if(x=='E') return 0; if(x=='S') return 1;
	if(x=='W') return 2; if(x=='N') return 3;
}
void build(int id,char *s)
{
	int len=strlen(s),u=0;
	ans[id]=len;
	for(int i=0;i<len;i++)
	{
		int v=getpos(s[i]);
		if(!trie[u].nxt[v])
			trie[u].nxt[v]=++cnt;
		fat[trie[u].nxt[v]]=u,u=trie[u].nxt[v];
	}
	idx[id]=u;
}
void getfail()
{
	queue<int>q;
	for(int i=0;i<4;i++)
		if(trie[0].nxt[i])
			q.push(trie[0].nxt[i]);
	while(!q.empty())
	{
		int u=q.front(); q.pop();
		for(int i=0;i<4;i++)
		{
			int v=trie[u].nxt[i],f=trie[u].fail;
			if(v) trie[v].fail=trie[f].nxt[i],q.push(v);
			else trie[u].nxt[i]=trie[f].nxt[i];
		}
	}
}
void acam(char *s)
{
	getfail();
	int len=strlen(s),pt=0;
	for(int i=0;i<len;i++)
	{
		pt=trie[pt].nxt[getpos(s[i])];
		int tmp=pt;
		while(tmp&&!trie[tmp].vis)
			trie[tmp].vis=1,tmp=trie[tmp].fail;
		trie[pt].vis=1;
	}
}
void getans(int id)
{
	int pt=idx[id];
	while(pt&&!trie[pt].vis) 
		ans[id]--,pt=fat[pt];
}
int main()
{
	int n,m;
	scanf("%d%d%s",&n,&m,txt);
	for(int i=1;i<=m;i++)
		scanf("%s",pat),build(i,pat);
	acam(txt);
	for(int i=1;i<=m;i++)
		getans(i),printf("%d\n",ans[i]);
}