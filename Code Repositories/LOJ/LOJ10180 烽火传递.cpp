#include<bits/stdc++.h>
#define maxn 200005
using namespace std;
int a[maxn],dp[maxn],q[maxn];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) 
		scanf("%d",&a[i]);
	for(int i=1,h=1,t=1;i<=n;i++)
	{
		if(h<=t&&q[h]<=i-m) h++;
		while(h<=t&&q[t]&&a[i]+dp[i-1]<=a[q[t]]+dp[q[t]-1]) t--;
		q[++t]=i;
		dp[i]=q[h]?a[q[h]]+dp[q[h]-1]:0;
	}
	printf("%d",dp[n]);
}