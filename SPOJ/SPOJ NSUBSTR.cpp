#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int maxn=1e6+5;
struct node
{	int nxt[26],len,fat; }trie[maxn<<1];
struct edge
{	
	int to,nxt; 
	edge(int to=0,int nxt=0):to(to),nxt(nxt){}
}e[maxn<<1];
char str[maxn]; 
int las=1,cnt1=1,head[maxn<<1],cnt2,siz[maxn<<1],ans[maxn];
void init()
{	memset(head,-1,sizeof(head)); }
void link(int u,int v)
{	e[cnt2]=edge(v,head[u]),head[u]=cnt2++; }
void build(int x)
{
	int p=las,np=las=++cnt1;
	trie[np].len=trie[p].len+1,siz[np]=1;
	while(p&&!trie[p].nxt[x]) 
		trie[p].nxt[x]=np,p=trie[p].fat;
	if(!p) { trie[np].fat=1; return; }
	int q=trie[p].nxt[x];
	if(trie[q].len==trie[p].len+1) 
	{	 trie[np].fat=q; return; }
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
		dfs(v),siz[u]+=siz[v];
	}
	ans[trie[u].len]=max(ans[trie[u].len],siz[u]);
}
int main()
{
	init(),scanf("%s",str);
	int len=strlen(str);
	for(int i=0;i<len;i++) 
		build(str[i]-'a');
	for(int i=2;i<=cnt1;i++) 
		link(trie[i].fat,i);
	dfs(1);
	for(int i=len-1;i;i--)
		ans[i]=max(ans[i],ans[i+1]);
	for(int i=1;i<=len;i++)
	printf("%d\n",ans[i]);
}