#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=6e6+5;
const ll mod=998244353;
ll ans[maxn],inv[maxn];
void init(int n)
{
	inv[1]=1;
	for(int i=2;i<=n;i++)
		inv[i]=(mod-mod/i)*inv[mod%i]%mod;
	for(int i=1;i<=n;i++)
		ans[i]=(ans[i-1]+inv[i]*inv[i]%mod)%mod;
}
int main()
{
	init(maxn-5);
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		printf("%lld\n",3LL*ans[n]%mod*inv[n]%mod);
	}
}