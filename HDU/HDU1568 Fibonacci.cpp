#include<bits/stdc++.h>
#define ll long long
using namespace std;
const double sq5=sqrt(5.0);
int fib[21]={0,1};
int main()
{
	for(int i=2;i<=20;i++)
		fib[i]=fib[i-1]+fib[i-2];
	double x=log10(1.0/sq5);
	int n;
	while(~scanf("%d",&n))
	{
		if(n<=20) 
		{	printf("%d\n",fib[n]); continue; }
		double logx=x+n*log10((1.0+sq5)/2);
		double ans=pow(10,logx-floor(logx))*1000;
		printf("%.0lf\n",floor(ans));
	}
}