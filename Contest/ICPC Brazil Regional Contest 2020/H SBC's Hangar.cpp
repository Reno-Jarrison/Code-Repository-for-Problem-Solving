#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;
ll w[55],c[55][55],a,b;
ll solve(ll x,int k)
{
	ll ans=0;
	for(int i=n;i;i--)
		if(w[i]<=x&&k)
			ans+=c[i-1][k--],x-=w[i];
	return ans+(k==0);
}
void getc(int n)
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
	int k;
	getc(50);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%lld",&w[i]);
	sort(w+1,w+n+1);
	scanf("%lld%lld",&a,&b);
	printf("%lld\n",solve(b,k)-solve(a-1,k));
}