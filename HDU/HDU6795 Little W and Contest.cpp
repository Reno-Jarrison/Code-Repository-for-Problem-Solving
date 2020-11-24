#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e5+5,mod=1e9+7;
int f[maxn];
ll r[maxn],c[maxn];
int find(int x)
{	return x==f[x]?x:find(f[x]); }
int main()
{
	int t,n,w,u,v;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		fill(r+1,r+n+1,0);
		fill(c+1,c+n+1,0);
		ll totr=0,totc=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&w),f[i]=i,
			w==1?(r[i]=1,totr++):(c[i]=1,totc++);
		}
		ll ans=(totc*(totc-1)/2*totr+totc*(totc-1)*(totc-2)/6)%mod;
		for(int i=1;i<n;i++)
		{
			printf("%lld\n",ans);
			scanf("%d%d",&u,&v);
			int fu=find(u),fv=find(v);
			ll tmp=0;
			tmp+=c[fu]*c[fv]%mod*(totr-r[fu]-r[fv])%mod;
			tmp+=c[fu]*r[fv]%mod*(totc-c[fu]-c[fv])%mod;
			tmp+=r[fu]*c[fv]%mod*(totc-c[fu]-c[fv])%mod;
			tmp+=c[fu]*c[fv]%mod*(totc-c[fu]-c[fv])%mod;
			ans=(ans-tmp%mod+mod)%mod;
			f[fu]=fv,r[fv]+=r[fu],c[fv]+=c[fu];
		}
		puts("0");
	}
}