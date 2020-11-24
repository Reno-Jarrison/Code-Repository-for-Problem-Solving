#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll C(int n,int m)
{
	double ans=1;
	m=min(m,n-m);
	for(int i=1;i<=m;i++)
		ans*=1.0*(n-i+1)/i;
	return (ll)(ans+0.5);
}
int main()
{
	int t,n,k;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		printf("%lld\n",C(n-1,k-1));
	}
}