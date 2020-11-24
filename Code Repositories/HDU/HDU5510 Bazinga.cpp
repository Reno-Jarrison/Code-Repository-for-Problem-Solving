#include<bits/stdc++.h>
using namespace std;
const int maxn=2e3+5;
int nxt[505][maxn],len[505];
char s[505][maxn];
void getnxt(int id)
{
	int i=0,j=-1;
	nxt[id][0]=-1;
	while(i<len[id])
		j==-1||s[id][i]==s[id][j]?nxt[id][++i]=++j:j=nxt[id][j];
}
bool kmp(int p,int t)
{
	int i=0,j=0;
	while(i<len[t])
	{
		j==-1||s[t][i]==s[p][j]?i++,j++:j=nxt[p][j];
		if(j==len[p]) return true;
	}
	return false;
}
int main()
{
	int t,n,ks=0;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%s",s[i]);
			len[i]=strlen(s[i]);
			getnxt(i);
		}
		int ans=-1,pt=1;
		for(int i=2;i<=n;i++)
		{
			while(pt<i&&kmp(pt,i)) pt++; 
			if(pt<i) ans=i;
		}
		printf("Case #%d: %d\n",++ks,ans);
	}
}