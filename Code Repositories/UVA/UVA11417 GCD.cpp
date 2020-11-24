#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2e5;
int cnt,p[maxn],phi[maxn+5];
ll sum[maxn+5],ans[maxn+5];
void getphi()
{
	for(int i=2;i<=maxn;i++)
	{
		if(!phi[i]) p[++cnt]=i,phi[i]=i-1;
		for(int j=1;i*p[j]<=maxn;j++)
			if(i%p[j]) phi[i*p[j]]=phi[i]*phi[p[j]];
			else { phi[i*p[j]]=phi[i]*p[j]; break; }
	}
	for(int i=2;i<=maxn;i++)
		sum[i]=sum[i-1]+phi[i];
}
int main()
{
	int n;
	getphi();
	while(scanf("%d",&n)&&n)
	{
		ll ans=0;
		for(int i=1;i<=n;i++)
			ans+=sum[n/i]*i;
		printf("%lld\n",ans);
	}
}
