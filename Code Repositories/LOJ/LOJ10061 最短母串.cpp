#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int maxn=1e3+5;
struct node
{	int nxt[26],fail,end; }trie[maxn];
struct qnode
{
	int pt,sta,id;
	qnode(int pt,int sta,int id):pt(pt),sta(sta),id(id){}
};
struct pnode
{
	int las,ch;
	pnode(int las=0,int ch=0):las(las),ch(ch){}
}path[maxn*(1<<12)];
char pat[55];
int cnt,vis[maxn][1<<12],tot;
void build(int id,char *s)
{
	int len=strlen(s),u=0;
	for(int i=0;i<len;i++)
	{
		int v=s[i]-'A';
		if(!trie[u].nxt[v])
			trie[u].nxt[v]=++cnt;
		u=trie[u].nxt[v];
	}
	trie[u].end|=(1<<(id-1));
}
void getfail()
{
	queue<int>q;
	for(int i=0;i<26;i++)
		if(trie[0].nxt[i])
			q.push(trie[0].nxt[i]);
	while(!q.empty())
	{
		int u=q.front(),f=trie[u].fail; q.pop();
		trie[u].end|=trie[f].end;
		for(int i=0;i<26;i++)
		{
			int v=trie[u].nxt[i];
			if(v) trie[v].fail=trie[f].nxt[i],q.push(v);
			else trie[u].nxt[i]=trie[f].nxt[i];
		}
	}
}
void print_path(int pt)
{
	pnode tmp=path[pt];
	if(pt==0) return;
	print_path(tmp.las);
	putchar(tmp.ch+'A');
}
void bfs(int end)
{
	queue<qnode>q;
	q.push(qnode(0,0,0));
	while(!q.empty())
	{
		qnode tmp=q.front(); q.pop();
		int u=tmp.pt,sta=tmp.sta,id=tmp.id;
		if(tmp.sta==end) { print_path(id); return; }
		for(int i=0;i<26;i++)
		{
			int v=trie[u].nxt[i],nsta=sta|trie[v].end;
			if(!v||vis[v][nsta]) continue;
			vis[v][nsta]=1;
			q.push(qnode(v,nsta,++tot));
			path[tot]=pnode(id,i);
		}
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%s",pat),build(i,pat);
	getfail(),bfs((1<<n)-1);
}