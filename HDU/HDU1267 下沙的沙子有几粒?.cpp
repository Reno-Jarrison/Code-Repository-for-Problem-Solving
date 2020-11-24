#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c[50][50];
void solve(int n)
{
	c[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		c[i][0]=c[i][i]=1;
		for(int j=1;j<i;j++)
			c[i][j]=c[i-1][j]+c[i-1][j-1];
	}
}
int main()
{
	solve(40);
	int n,m;
	while(~scanf("%d%d",&m,&n))
		printf("%lld\n",c[m+n][m]-c[m+n][n-1]);
}