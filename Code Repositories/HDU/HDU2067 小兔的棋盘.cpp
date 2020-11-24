#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c[80][80];
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
	solve(70);
	int n,ks=0;
	while(scanf("%d",&n)&&~n)
		printf("%d %d %lld\n",++ks,n,(c[2*n][n]-c[2*n][n-1])*2);
}