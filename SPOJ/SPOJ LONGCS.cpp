#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1e4+5,inf=0x3f3f3f3f;
struct node
{	int nxt[26],len,fat; }trie[maxn<<1];
struct edge
{
	int to,nxt;
	edge(int to=0,int nxt=0):to(to),nxt(nxt){}
}e[maxn*3];
char str[maxn];
int las=1,cnt1=1,cnt2,head[maxn<<1];
int mxv[maxn<<1],mnv[maxn<<1];
void init()
{
	las=cnt1=1,cnt2=0;
	memset(trie,0,sizeof(trie));
	memset(head,-1,sizeof(head));
	memset(mnv,inf,sizeof(mnv));
}
void link(int u,int v)
{	e[cnt2]=edge(v,head[u]),head[u]=cnt2++; }
void build(int x)
{
	int p=las,np=las=++cnt1;
	trie[np].len=trie[p].len+1;
	while(p&&!trie[p].nxt[x])
		trie[p].nxt[x]=np,p=trie[p].fat;
	if(!p) { trie[np].fat=1; return; }
	int q=trie[p].nxt[x];
	if(trie[q].len==trie[p].len+1)
		{	trie[np].fat=q; return; }
	int nq=++cnt1;
	trie[nq]=trie[q];
	trie[nq].len=trie[p].len+1;
	trie[q].fat=trie[np].fat=nq;
	while(p&&trie[p].nxt[x]==q)
		trie[p].nxt[x]=nq,p=trie[p].fat;
}
void dfs(int u)
{
	for(int i=head[u];~i;i=e[i].nxt)
	{
		int v=e[i].to;
		dfs(v),mxv[u]=max(mxv[u],mxv[v]);
	}
	mxv[u]=min(mxv[u],trie[u].len);
}
void sam(char *s)
{
	memset(mxv,0,sizeof(mxv));
	int len=strlen(s),u=1,tmp=0;
	for(int i=0;i<len;i++)
	{
		int v=s[i]-'a';
		while(u&&!trie[u].nxt[v])
			u=trie[u].fat,tmp=trie[u].len;
		if(!u) u=1;
		if(trie[u].nxt[v])
			u=trie[u].nxt[v],tmp++;
		mxv[u]=max(mxv[u],tmp);
	}
	dfs(1);
	for(int i=1;i<=cnt1;i++)
		mnv[i]=min(mnv[i],mxv[i]);
}
int main()
{
	int k,t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&k);
		init(),scanf("%s",str);
		int len=strlen(str),ans=0;
		if(k==1) { printf("%d\n",len); continue; }
		for(int i=0;i<len;i++)
			build(str[i]-'a');
		for(int i=2;i<=cnt1;i++)
			link(trie[i].fat,i);
		for(int i=1;i<k;i++)
			scanf("%s",str),sam(str);
		for(int i=1;i<=cnt1;i++)
			ans=max(ans,mnv[i]);
		printf("%d\n",ans);
	}
}