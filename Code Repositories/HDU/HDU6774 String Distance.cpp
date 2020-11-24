#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5,inf=0x3f3f3f3f;
char txt[maxn],pat[25];
int nxt[maxn][26],dp[25][25];
int main()
{
	int t,q,l,r;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s%s",txt+1,pat+1);
		int n=strlen(txt+1),m=strlen(pat+1);
		memset(nxt[n+1],inf,sizeof(nxt[n+1]));
		for(int i=n;i;i--)
			for(int j=0;j<26;j++)
				nxt[i][j]=nxt[i+1][j],nxt[i][txt[i]-'a']=i;
		scanf("%d",&q);
		while(q--)
		{
			scanf("%d%d",&l,&r);
			int cnt=0;
			memset(dp,inf,sizeof(dp));
			dp[0][0]=l-1;
			for(int i=1;i<=m;i++)
			{
				int cur=pat[i]-'a';
				for(int j=0;j<=i;j++)
				{
					dp[i][j]=dp[i-1][j];
					if(j)
					{
						int pt=dp[i-1][j-1];
						if(pt>=r) continue;
						dp[i][j]=min(dp[i][j],nxt[pt+1][cur]);
					}
					if(dp[i][j]<=r) cnt=max(cnt,j);
				}
			}
			printf("%d\n",r-l+1+m-cnt*2);
		}
	}
}