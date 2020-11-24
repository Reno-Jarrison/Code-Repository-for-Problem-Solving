#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=5e5+5;
struct node
{	int nxt[26],len,fat; }trie[maxn<<1];
char str[maxn];
int las=1,cnt=1,sum[maxn<<1],siz[maxn<<1],bkt[maxn<<1],rk[maxn<<1];
void build(int x)
{
	int p=las,np=las=++cnt;
	trie[np].len=trie[p].len+1,siz[np]=1;
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
	if(k<=siz[u]) return;
	k-=siz[u];
	for(int i=0;i<26;i++)
	{
		int v=trie[u].nxt[i];
		if(k>sum[v]) { k-=sum[v]; continue; }
		putchar('a'+i),dfs(v,k); return; 
	}
}
int main()
{
	int flag,k;
	scanf("%s%d%d",str,&flag,&k);
	int len=strlen(str);
	for(int i=0;i<len;i++)
		build(str[i]-'a');
	topsort();
	for(int i=cnt;i;i--)
		if(!flag) siz[i]=1; 
		else siz[trie[rk[i]].fat]+=siz[rk[i]];
	for(int i=1;i<=cnt;i++) sum[i]=siz[i];
	sum[1]=siz[1]=0;
	for(int i=cnt;i;i--)
		for(int j=0;j<26;j++)
			sum[rk[i]]+=sum[trie[rk[i]].nxt[j]];
	if(sum[1]<k) printf("-1");
	else dfs(1,k);
}