#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int maxn=1e6+5,maxm=5e5+5;
struct node
{
	int nxt[26],fail,end;
}trie[maxm];
int cnt=0;
char pat[maxm],txt[maxn];
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
	trie[u].end++;
}
void getfail()
{
	queue<int>q;
	for(int i=0;i<26;i++)
		if(trie[0].nxt[i])
			q.push(trie[0].nxt[i]);
	while(!q.empty())
	{
		int u=q.front(); q.pop();
		for(int i=0;i<26;i++)
		{
			int v=trie[u].nxt[i],f=trie[u].fail;
			if(v) trie[v].fail=trie[f].nxt[i],q.push(v);
			else trie[u].nxt[i]=trie[f].nxt[i];
		}
	}
}
#include<iostream>
int acam(char *s)
{
	getfail();
	int ans=0,pt=0,len=strlen(s);
	for(int i=0;i<len;i++)
	{
		pt=trie[pt].nxt[s[i]-'a'];
		int tmp=pt;
		while(tmp&&trie[tmp].end!=-1)
		{
			ans+=trie[tmp].end;
			trie[tmp].end=-1;
			tmp=trie[tmp].fail;
		}
	}
	return ans;
}
int main()
{
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		memset(trie,0,sizeof(trie));
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%s",pat),build(pat);
		scanf("%s",txt),printf("%d\n",acam(txt));
	}
}