#include<cstdio>
using namespace std;
const int maxn=1e5+5;
const double eps=1e-7;
double dp[maxn]={1,1};
int main()
{
	int k;
	for(int i=2;i<maxn;i++)
		dp[i]=1.0/i+(1-1.0/i)*(1-dp[i-1]);
	while(~scanf("%d",&k))
	{
		k++;
		if(dp[k]-0.5>eps) puts("1");
		else if(0.5-dp[k]>eps) puts("2");
		else puts("0");
	}
}