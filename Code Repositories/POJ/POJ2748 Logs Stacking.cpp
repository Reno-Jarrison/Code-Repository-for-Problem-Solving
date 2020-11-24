#include<stdio.h>
#define T 75000
int dp[T]={1,1}; 
int main()
{
	int t,n;
	scanf("%d",&t);
	for(int i=2;i<T;i++)
		dp[i]=(3*dp[i-1]-dp[i-2]+100000)%100000;
	while(t--)
		scanf("%d",&n),printf("%d\n",dp[n%T]);
} 