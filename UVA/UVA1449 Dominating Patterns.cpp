#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int maxn=2e4+5,maxm=1e6+5;
struct node
{	int nxt[26],fail,end; }trie[maxn];
int idx[maxn],cnt,ans[maxn];
char pat[155][100],txt[maxm];
void build(int id,char *s)
{
	int len=strlen(s),u=0;
	for(int i=0;i<len;i++)
	{
		int v=s[i]-'a';
		if(!trie[u].nxt[v])
			trie[u].nxt[v]=++cnt;
		u=trie[u].nxt[v];
	}
	trie[u].end=1,idx[id]=u;
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
int acam(int n,char *s)
{
	int len=strlen(s),pt=0,tot=0;
	for(int i=0;i<len;i++)
	{
		pt=trie[pt].nxt[s[i]-'a'];
		int tmp=pt;
		while(tmp&&trie[tmp].end)
			ans[tmp]++,tmp=trie[tmp].fail;
	}
	for(int i=1;i<=n;i++)
		tot=max(tot,ans[idx[i]]);
	return tot;
}
int main()
{
	int n,flag;
	while(scanf("%d",&n)&&n)
	{
		memset(trie,0,sizeof(trie));
		memset(ans,0,sizeof(ans));
		for(int i=1;i<=n;i++)
			scanf("%s",pat[i]),build(i,pat[i]);
		getfail(),scanf("%s",txt);
		flag=acam(n,txt);
		printf("%d\n",flag);
		for(int i=1;i<=n;i++)
			if(ans[idx[i]]==flag)
				printf("%s\n",pat[i]);
	}
}