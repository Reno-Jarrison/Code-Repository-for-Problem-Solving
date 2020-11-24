#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=9e4+5;
struct node
{	int nxt[26],len,fat; }trie[maxn<<1];
char str[maxn];
int las=1,cnt=1,dp[maxn<<1],bkt[maxn<<1],rk[maxn<<1];
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
	trie[q].fat=trie[np].fat=nq;
	while(p&&trie[p].nxt[x]==q)
		trie[p].nxt[x]=nq,p=trie[p].fat;
}
void topsort()
{
	for(int i=1;i<=cnt;i++) bkt[trie[i].len]++;
	for(int i=1;i<=cnt;i++) bkt[i]+=bkt[i-1];
	for(int i=1;i<=cnt;i++) rk[bkt[trie[i].len]--]=i;
}
void dfs(int u,int k)
{
	if(!k--) return;
	for(int i=0;i<26;i++)
	{
		int v=trie[u].nxt[i];
		if(k>=dp[v]) { k-=dp[v]; continue; }
		putchar('a'+i),dfs(v,k); return; 
	}
}
int main()
{
	int n,k;
	scanf("%s%d",str,&n);
	int len=strlen(str);
	for(int i=0;i<len;i++)
		build(str[i]-'a');
	topsort();
	for(int i=cnt;i;i--)
	{
		dp[rk[i]]=1;
		for(int j=0;j<26;j++)
			dp[rk[i]]+=dp[trie[rk[i]].nxt[j]];
	}
	for(int i=1;i<=n;i++)
		scanf("%d",&k),dfs(1,k),puts("");
}
