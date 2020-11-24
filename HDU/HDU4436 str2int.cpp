#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=1e5+5,mod=2012;
struct node
{	int nxt[11],len,fat; }trie[maxn<<1];
int las,cnt,bkt[maxn<<1],rk[maxn<<1];
int dp1[maxn<<1],dp2[maxn<<1];
char str[maxn];
void init()
{	
	las=cnt=1;
	memset(trie,0,sizeof(trie)); 
	memset(bkt,0,sizeof(bkt));
	memset(dp1,0,sizeof(dp1));
	memset(dp2,0,sizeof(dp2));
}
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
int sam()
{
	int ans=0;
	dp1[1]=1;
	for(int i=1;i<=cnt;i++)
	{
		int u=rk[i];
		ans=(ans+dp2[u])%mod;
		for(int j=(u==1?1:0);j<10;j++)
		{
			int v=trie[u].nxt[j];
			if(!v) continue;
			dp1[v]=(dp1[v]+dp1[u])%mod;
			dp2[v]=(dp2[v]+dp2[u]*10+dp1[u]*j)%mod;
		}
	}
	return ans;
}
int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		init();
		for(int i=1;i<=n;i++)
		{
			scanf("%s",str);
			int len=strlen(str);
			for(int i=0;i<len;i++)
				build(str[i]-'0');
			build(10);
		}
		topsort();
		printf("%d\n",sam());
	}
}