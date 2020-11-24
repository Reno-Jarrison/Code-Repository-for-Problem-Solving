#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5,mod=1e4+7;
int nxt[maxn],dp[maxn];
char s[maxn];
void getnxt(char *s,int len)
{
	int i=0,j=-1;
	nxt[0]=-1;
	while(i<len)
		j==-1||s[i]==s[j]?nxt[++i]=++j:j=nxt[j];
}
int main()
{
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%s",&n,s);
		int ans=0,len=strlen(s);
		getnxt(s,len);
		for(int i=1;i<=n;i++)
		{
			dp[i]=(dp[nxt[i]]+1)%mod;
			ans=(ans+dp[i])%mod;
		}
		printf("%d\n",ans);
	}
}