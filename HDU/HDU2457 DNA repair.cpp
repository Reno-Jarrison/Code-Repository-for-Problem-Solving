#include<iostream>
#include<queue>
#include<cstring>
#define maxn 1005
#define inf 0x3f3f3f3f
using namespace std;
struct node
{
	int fail,next[4],end;
}trie[maxn];
int cnt,n,casenum,dp[maxn][maxn];
char ptn[25],txt[maxn];
inline int tran(char x)
{
	if(x=='A') return 0;
	if(x=='G') return 1;
	if(x=='C') return 2;
	if(x=='T') return 3;
}
inline void build(char *s)
{
	int len=strlen(s),root=0;
	for(int i=0;i<len;i++)
	{
		int son=tran(s[i]);
		if(!trie[root].next[son])
			trie[root].next[son]=++cnt;
		root=trie[root].next[son];
	}
	trie[root].end=1; 
}
void getfail()
{
	queue<int>nodeq;
	for(int i=0;i<4;i++)
		if(trie[0].next[i])
			nodeq.push(trie[0].next[i]);
	while(!nodeq.empty())
	{
		int tnode=nodeq.front();
		nodeq.pop();
		for(register int i=0;i<4;i++)
			if(trie[tnode].next[i])
			{
				trie[trie[tnode].next[i]].fail=trie[trie[tnode].fail].next[i];
				trie[trie[tnode].next[i]].end|=trie[trie[trie[tnode].next[i]].fail].end;
				nodeq.push(trie[tnode].next[i]);
			}
			else trie[tnode].next[i]=trie[trie[tnode].fail].next[i];
	}
}
int main()
{
	while(scanf("%d",&n)&&n)
	{
		casenum++;
		memset(trie,0,sizeof(trie));
		memset(dp,0x3f,sizeof(dp));
		cnt=dp[0][0]=0;
		for(register int i=1;i<=n;i++)
			scanf("%s",ptn),build(ptn);
		getfail();
		scanf("%s",txt);
		int len=strlen(txt),ans=inf;
		for(register int i=1;i<=len;i++)
		for(register int j=0;j<=cnt;j++)
			if(dp[i-1][j]!=inf) 
				for(register int k=0;k<4;k++)
				{
					int pt=trie[j].next[k];
					if(!trie[pt].end)
						dp[i][pt]=min(dp[i][pt],dp[i-1][j]+(k!=tran(txt[i-1])));
				}
		for(register int i=0;i<=cnt;i++)
			ans=min(ans,dp[len][i]);
		if(ans==inf) ans=-1;
		printf("Case %d: %d\n",casenum,ans);
	}
}