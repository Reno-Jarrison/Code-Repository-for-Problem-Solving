#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2e5;
int cnt,p[maxn],phi[maxn+5];
ll f[maxn+5],ans[maxn+5];
void pretreat()
{
	for(int i=2;i<=maxn;i++)
	{
		if(!phi[i]) p[++cnt]=i,phi[i]=i-1;
		for(int j=1;i*p[j]<=maxn;j++)
			if(i%p[j]) phi[i*p[j]]=phi[i]*phi[p[j]];
			else { phi[i*p[j]]=phi[i]*p[j]; break; }
	}
	for(int i=1;i<=maxn;i++)
		for(int j=2*i;j<=maxn;j+=i)
			f[j]+=i*phi[j/i];
	for(int i=2;i<=maxn;i++)
		ans[i]=ans[i-1]+f[i];
}
int main()
{
	int n;
	pretreat();
	while(scanf("%d",&n)&&n)
		printf("%lld\n",ans[n]);
}
