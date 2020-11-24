#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll d[30],c[30][30];
void solve(int n)
{
	d[1]=0,d[0]=d[2]=c[0][0]=1;
	for(int i=3;i<=n;i++)
		d[i]=(d[i-1]+d[i-2])*(i-1);
	for(int i=1;i<=n;i++)
	{
		c[i][0]=c[i][i]=1;
		for(int j=1;j<i;j++)
			c[i][j]=c[i-1][j-1]+c[i-1][j];
	}
}
int main()
{
	solve(25);
	int n;
	while(scanf("%d",&n)&&n)
	{
		ll ans=0;
		for(int i=0;i<=n/2;i++)
			ans+=d[i]*c[n][i];
		printf("%lld\n",ans);
	}
}