#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
double dp[maxn];
int main()
{
	int n,a,b;
	scanf("%d%d%d",&n,&a,&b);
	int m=b-a+1;
	double sum=0;
	for(int i=1;i<=n;i++)
	{
		if(i>=a) sum+=dp[i-a];
		if(i>=b+1) sum-=dp[i-b-1];
		if(a>0)
			dp[i]=sum/m+1;
		else
			dp[i]=(sum+m)/(m-1),sum+=dp[i];
	}
	printf("%.5lf\n",dp[n]);
}