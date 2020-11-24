#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2e3+5,mod=1e5+7;
ll c[maxn][maxn];
void getc(int n)
{
	c[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		c[i][0]=c[i][i]=1;
		for(int j=1;j<n;j++)
			c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
	}
}
ll cat(int n)
{	return (c[2*n][n]-c[2*n][n-1]+mod)%mod; }
int main()
{
	int t,n;
	getc(2e3);
	scanf("%d",&t);
	while(t--)
		scanf("%d",&n),printf("%lld\n",cat(n-2));
}