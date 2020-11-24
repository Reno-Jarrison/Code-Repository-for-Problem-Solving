#include<cstdio>
#include<cstring>
#define ll long long
using namespace std;
const int maxn=2e5+5;
struct node
{	int nxt[26],len,fat; }trie[maxn<<2];
int cnt=1,siz[maxn<<2][2],bkt[maxn<<2],rk[maxn<<2];
char str[maxn];
int insert(int x,int p,int id)
{
	int np=trie[p].nxt[x];
	if(np&&trie[np].len==trie[p].len+1) return np;
	np=++cnt,trie[np].len=trie[p].len+1;
	while(p&&!trie[p].nxt[x])
		trie[p].nxt[x]=np,p=trie[p].fat;
	if(!p) { trie[np].fat=1; return np; }
	int q=trie[p].nxt[x];
	if(trie[q].len==trie[p].len+1)
		trie[np].fat=q;
	else
	{
		int nq=++cnt;
		trie[nq]=trie[q];
		trie[nq].len=trie[p].len+1;
		trie[np].fat=trie[q].fat=nq;
		while(p&&trie[p].nxt[x]==q)
			trie[p].nxt[x]=nq,p=trie[p].fat;
	}
	return np;
}
void build(char *s,int id)
{
	int pt=1,len=strlen(s);
	for(int i=0;i<len;i++)
		pt=insert(s[i]-'a',pt,id),siz[pt][id]=1;
}
void topsort()
{
	for(int i=1;i<=cnt;i++) bkt[trie[i].len]++;
	for(int i=1;i<=cnt;i++) bkt[i]+=bkt[i-1];
	for(int i=1;i<=cnt;i++) rk[bkt[trie[i].len]--]=i;
}
int main()
{
	scanf("%s",str),build(str,0);
	scanf("%s",str),build(str,1);
	topsort();
	ll ans=0;
	for(int i=cnt;i;i--)
	{
		int pt=rk[i],f=trie[pt].fat;
		siz[f][0]+=siz[pt][0];
		siz[f][1]+=siz[pt][1];
		ans+=1LL*siz[pt][0]*siz[pt][1]*(trie[pt].len-trie[f].len);
	}		
	printf("%lld",ans);
}