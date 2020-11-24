#include<bits/stdc++.h>
#define maxn 305
int a[maxn],dp[maxn][maxn],ans[maxn][maxn];
using namespace std;
struct range { int l,r; };
void bfs(int n)
{
	queue<range>q;
	q.push({1,n});
	while(!q.empty())
	{
		range pt=q.front();
		q.pop();
		if(pt.l==pt.r) continue;
		int k=ans[pt.l][pt.r];
		q.push({pt.l,k}),q.push({k+1,pt.r});
		printf("%d ",k);
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=2;i<=n;i++)
		for(int l=1,r=l+i-1;r<=n;l++,r++)
			for(int k=r-1;k>=l;k--)
			{
				int val=(a[l]+a[r])*a[k]+dp[l][k]+dp[k+1][r];
				if(dp[l][r]<=val) dp[l][r]=val,ans[l][r]=k;
			}
	printf("%d\n",dp[1][n]);
	bfs(n);
	return 0;
}