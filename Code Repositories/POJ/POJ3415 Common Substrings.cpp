#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int maxn=1e5+5;
struct node
{	int nxt[65],len,fat; }trie[maxn<<1];
int las,cnt,siz[maxn<<1],bkt[maxn<<1],rk[maxn<<1];
char str[maxn];
ll ans,dp[maxn<<1];
void init()
{	
	las=cnt=1,ans=0;
	memset(trie,0,sizeof(trie)); 
	memset(dp,0,sizeof(dp));
	memset(siz,0,sizeof(siz));
}
void build(int x)
{
	int p=las,np=las=++cnt;
	trie[np].len=trie[p].len+1;
	siz[np]=1;
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
void topsort()
{
	memset(bkt,0,sizeof(bkt));
	for(int i=1;i<=cnt;i++) bkt[trie[i].len]++;
	for(int i=1;i<=cnt;i++) bkt[i]+=bkt[i-1];
	for(int i=1;i<=cnt;i++) rk[bkt[trie[i].len]--]=i;
}
void sam(char *s,int k)
{
	int len=strlen(s),u=1,tmp=0;
	for(int i=0;i<len;i++)
	{
		int v=s[i]-'A';
		while(u&&!trie[u].nxt[v])
			u=trie[u].fat,tmp=trie[u].len;
		if(!u) u=1;
		if(trie[u].nxt[v])
			u=trie[u].nxt[v],tmp++;
		int f=trie[u].fat;
		if(tmp>=k)
		{
			ans+=1LL*(tmp-max(k,trie[f].len+1)+1)*siz[u];
			if(trie[f].len>=k) dp[f]++;
		}
	}
	for(int i=cnt;i;i--)
	{
		int pt=rk[i],f=trie[pt].fat;
		ans+=1LL*(trie[pt].len-max(k,trie[f].len+1)+1)*siz[pt]*dp[pt];
		if(trie[f].len>=k) dp[f]+=dp[pt];
	}
}
int main()
{
	int k;
	while(~scanf("%d",&k)&&k)
	{
		init(),scanf("%s",str);
		int len=strlen(str);
		for(int i=0;i<len;i++)
			build(str[i]-'A');
		topsort();
		for(int i=cnt;i;i--)
			siz[trie[rk[i]].fat]+=siz[rk[i]];
		scanf("%s",str),sam(str,k);
		printf("%lld\n",ans);
	}
}