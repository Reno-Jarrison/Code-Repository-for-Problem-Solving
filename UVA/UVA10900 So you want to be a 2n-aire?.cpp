#include<cstdio>
#include<algorithm>
using namespace std;
double dp[35];
int main()
{
	int n;
	double t;
	while(scanf("%d%lf",&n,&t)&&n)
	{
		dp[n]=(double)(1<<n);
		for(int i=n-1;i>=0;i--)
		{
			double p=max((double)(1<<i)/dp[i+1],t);
			double q=(p-t)/(1.0-t);
			dp[i]=q*(1<<i)+(1.0-q)*(p+1.0)*dp[i+1]/2;
		}
		printf("%.3lf\n",dp[0]);
	}
}