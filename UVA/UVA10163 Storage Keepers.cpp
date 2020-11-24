#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+5;
int p[maxn],dp[105],n,m;
bool check(int mval)
{
	if(!mval) return true;
	int cnt=0;
	for(int i=1;i<=m;i++)
		cnt+=p[i]/mval;
	return cnt>=n;
}
int main()
{
	while(scanf("%d%d",&n,&m)&&n)
	{
		int l=0,r=0;
		for(int i=1;i<=m;i++)
			scanf("%d",&p[i]),r+=p[i];
		while(l<=r)
		{
			int mid=(l+r)>>1;
			if(check(mid)) l=mid+1;
			else r=mid-1;
		}
		if(!r) {puts("0 0"); continue; }
		memset(dp,0x3f,sizeof(dp)),dp[0]=0;
		for(int i=1;i<=m;i++)
			for(int j=n;j;j--)
				for(int k=1;k<=min(j,p[i]/r);k++)
					dp[j]=min(dp[j],dp[j-k]+p[i]);
		printf("%d %d\n",r,dp[n]);
	}
}