#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=1e4+5;
struct node
{	int nxt[26],len,fat; }trie[maxn<<2];
char str[maxn];
#include<iostream>
int las,cnt;
void init()
{	las=cnt=1,memset(trie,0,sizeof(trie)); }
void build(int x)
{
	int p=las,np=las=++cnt;
	trie[np].len=trie[p].len+1;
	while(p&&!trie[p].nxt[x])
		trie[p].nxt[x]=np,p=trie[p].fat;
	if(!p) { trie[np].fat=1; return; }
	int q=trie[p].nxt[x];
	if(trie[q].len==trie[p].len+1)
		{	trie[np].fat=q; return; }
	int nq=++cnt;
	trie[nq]=trie[q];
	trie[nq].len=trie[p].len+1;
	trie[np].fat=trie[q].fat=nq;
	while(p&&trie[p].nxt[x]==q)
		trie[p].nxt[x]=nq,p=trie[p].fat;
}
void dfs(int u,int step,int len)
{
	if(step==len+1) { printf("%d\n",trie[u].len-len); return; }
	for(int i=0;i<26;i++)
	{
		int v=trie[u].nxt[i];
		if(!v) continue;
		dfs(v,step+1,len);
		return; 
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		init(),scanf("%s",str);
		int len=strlen(str);
		for(int i=0;i<len;i++) build(str[i]-'a');
		for(int i=0;i<len;i++) build(str[i]-'a');
		dfs(1,0,len);
	}
}