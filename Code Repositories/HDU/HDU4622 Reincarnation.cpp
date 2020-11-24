#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=2e3+5,maxm=1e4+5;
struct node
{	int nxt[26],len,fat; }trie[maxn<<1];
char str[maxn];
int las,cnt,ans[maxn][maxn];
void init()
{	
	las=cnt=1;
	memset(trie,0,sizeof(trie)); 
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

int main()
{
	int t,n,pt,l,r;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s%d",str+1,&n);
		int len=strlen(str+1);
		for(int i=1;i<=len;i++)
		{
			init();
			for(int j=i;j<=len;j++)
			{
				build(str[j]-'a');
				ans[i][j]=ans[i][j-1]+trie[las].len-trie[trie[las].fat].len;
			}
		}
		for(int i=1;i<=n;i++)
			scanf("%d%d",&l,&r),printf("%d\n",ans[l][r]);
	}
}