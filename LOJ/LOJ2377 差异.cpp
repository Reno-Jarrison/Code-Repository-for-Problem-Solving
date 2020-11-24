#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#define ll long long
using namespace std;
const int maxn=5e5+5;
struct node
{	int nxt[26],len,fat; }trie[maxn<<1];
int las=1,cnt=1,bkt[maxn<<1],rk[maxn<<1],siz[maxn<<1];
char str[maxn];
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
int main()
{
	scanf("%s",str);
	int len=strlen(str);
	for(int i=0;i<len;i++)
		build(str[i]-'a');
	topsort();
	ll ans=0;
	for(int i=cnt;i;i--)
	{
		int pt=rk[i],f=trie[pt].fat;
		siz[f]+=siz[pt];
		ans+=1LL*siz[pt]*(len-siz[pt])*(trie[pt].len-trie[f].len);
	}
	printf("%lld",ans);
}