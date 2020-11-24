#include<bits/stdc++.h>
#define maxn 50005
using namespace std;
int a[maxn],dp[maxn],q[maxn];
bool check(int len,int n,int t)
{
	memset(dp,0,sizeof(dp));
	for(int i=1,h=1,t=1;i<=n;i++)
	{
		if(h<=t&&q[h]<i-len) h++;
		while(h<=t&&a[q[t]]+dp[q[t]-1]>=a[i]+dp[i-1]) t--;
		q[++t]=i;
		dp[i]=q[h]?a[q[h]]+dp[q[h]-1]:0;
	}
	return dp[n]<=t;
}
int main()
{
	int n,t,l=1,r;
	scanf("%d%d",&n,&t),r=n;
	for(int i=1;i<=n;i++) 
		scanf("%d",&a[i]);
	while(l<=r)
	{
		int m=(l+r)>>1;
		if(check(m,n,t)) r=m-1;
		else l=m+1;
	}
	printf("%d",l);
}