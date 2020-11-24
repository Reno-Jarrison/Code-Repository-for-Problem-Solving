#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4;
int c[55],dp[maxn];
int main()
{
	int T,n,t,ks=0;
	scanf("%d",&T);
	while(T--)
	{
		int mxv=0;
		scanf("%d%d",&n,&t);
		for(int i=1;i<=n;i++)
			scanf("%d",&c[i]),mxv+=c[i];
		memset(dp,-0x3f,sizeof(dp));
		dp[0]=0,t=min(t-1,mxv);
		for(int i=1;i<=n;i++)
			for(int j=t;j>=c[i];j--)
				dp[j]=max(dp[j],dp[j-c[i]]+1);
		int ans=-1,tot=0;
		for(int i=0;i<=t;i++)
			if(dp[i]>=ans) ans=dp[i],tot=i;
		printf("Case %d: %d %d\n",++ks,ans+1,tot+678);
	}
}
