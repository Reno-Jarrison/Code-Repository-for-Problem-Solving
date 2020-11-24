#include<bits/stdc++.h>
using namespace std;
const int maxn=55,maxm=1e4+5,inf=0x3f3f3f3f; 
int dp[maxn*maxn][maxn],a[maxn][maxn],exi[maxn*maxn][maxn],idx;
int cnt[maxn],id[maxm],tot[maxm],pre[maxn],suc[maxn];
int main()
{
	int n,ks=0;
	while(~scanf("%d",&n))
	{
		memset(id,0,sizeof(id)),idx=0;
		memset(exi,0,sizeof(exi));
		memset(tot,0,sizeof(tot));
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&cnt[i]);
			for(int j=1;j<=cnt[i];j++)
				scanf("%d",&a[i][j]),id[a[i][j]]=1;
		}
		for(int i=1;i<maxm;i++)
			if(id[i]) id[i]=++idx;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=cnt[i];j++)
				exi[id[a[i][j]]][i]=1;
		for(int i=1;i<=idx;i++)
			for(int j=1;j<=n;j++)
				tot[i]+=exi[i][j];
		for(int i=1;i<=idx;i++)
		{
			int tmp=inf;
			for(int j=1;j<=n;j++)
				tmp=min(tmp,dp[i-1][j]+tot[i]);
			for(int j=1;j<=n;j++)
				dp[i][j]=exi[i][j]?tmp:inf;
			if(tot[i]==1)
				for(int j=1;j<=n;j++) if(exi[i][j])
					dp[i][j]=i>1?min(dp[i][j],dp[i-1][j]):1;
			memset(pre,inf,sizeof(pre));
			memset(suc,inf,sizeof(suc));
			for(int j=1;j<=n;j++)
				pre[j]=min(pre[j-1],exi[i-1][j]&&exi[i][j]?dp[i-1][j]+tot[i]-1:inf);
			for(int j=n;j;j--)
				suc[j]=min(suc[j+1],exi[i-1][j]&&exi[i][j]?dp[i-1][j]+tot[i]-1:inf);
			for(int j=1;j<=n;j++) if(exi[i][j])
				dp[i][j]=min(dp[i][j],min(pre[j-1],suc[j+1]));
		}
		int ans=inf;
		for(int i=1;i<=n;i++)
			ans=min(ans,dp[idx][i]);
		printf("Case %d: %d\n",++ks,2*ans-n-1);
	}
}