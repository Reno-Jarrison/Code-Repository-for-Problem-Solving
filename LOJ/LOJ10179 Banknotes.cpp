#include<bits/stdc++.h>
#define ll long long
#define maxn 20005 
int w[205],c[205],dp[205][maxn],q[maxn];
using namespace std;
inline bool check(int i,int j,int k,int m)
{	return dp[i-1][j*w[i]+m]-j<=dp[i-1][k*w[i]+m]-k; }
int main()
{
	int n,k;
	scanf("%d",&n);
	memset(dp,0x3f,sizeof(dp));
	for(int i=1;i<=n;i++) scanf("%d",&w[i]); 
	for(int i=1;i<=n;i++) scanf("%d",&c[i]); 
	scanf("%d",&k);
	dp[0][0]=0;
	for(int i=1;i<=n;i++)
		for(int mod=0;mod<w[i];mod++)
			for(int j=0,h=1,t=0;j*w[i]+mod<=k;j++)
			{
				if(h<=t&&q[h]<j-c[i]) h++;
				while(h<=t&&check(i,j,q[t],mod)) t--;
				q[++t]=j;
				dp[i][j*w[i]+mod]=dp[i-1][q[h]*w[i]+mod]-q[h]+j;
			}
	printf("%d",dp[n][k]);
}