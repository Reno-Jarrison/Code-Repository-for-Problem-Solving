#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int maxn=1e5+5;
struct node1
{	int nxt[26],fail,len,end; }trie[maxn];
struct node2
{
	int id; char c;
	node2(int id=0,char c=0):id(id),c(c){}
}stack[maxn];
int cnt,len[maxn],tp;
char pat[maxn],txt[maxn];
void build(char *s)
{
	int len=strlen(s),u=0;
	for(int i=0;i<len;i++)
	{
		int v=s[i]-'a';
		if(!trie[u].nxt[v])
			trie[u].nxt[v]=++cnt;
		u=trie[u].nxt[v];
	}
	trie[u].len=len,trie[u].end=1;
}
void getfail()
{
	queue<int>q;
	for(int i=0;i<26;i++)
		if(trie[0].nxt[i]) q.push(trie[0].nxt[i]);
	while(!q.empty())
	{
		int u=q.front(); q.pop();
		for(int i=0;i<26;i++)
		{
			int v=trie[u].nxt[i],f=trie[u].fail,fnxt=trie[f].nxt[i];
			if(v) q.push(v),trie[v].fail=fnxt;
			else trie[u].nxt[i]=fnxt;
		}
	}
}
void acam(char *s)
{
	int len=strlen(s),pt=0;
	for(int i=0;i<len;i++)
	{
		pt=trie[pt].nxt[s[i]-'a'],stack[++tp]=node2(pt,s[i]);
		if(trie[pt].end) tp-=trie[pt].len,pt=stack[tp].id; 
	}
}
int main()
{
	int n;
	scanf("%s%d",txt,&n);
	for(int i=1;i<=n;i++)
		scanf("%s",pat),build(pat);
	getfail(),acam(txt);
	for(int i=1;i<=tp;i++) putchar(stack[i].c);
}