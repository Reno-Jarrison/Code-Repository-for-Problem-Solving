#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+5;
double dp[maxn];
int main()
{
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		dp[n]=0;
		for(int i=n-1;i>=0;i--)
			dp[i]=dp[i+1]+1.0*n/(n-i);
		printf("%.2lf\n",dp[0]);
	}
}
