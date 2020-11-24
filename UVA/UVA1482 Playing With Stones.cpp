#include<cstdio>
#define ll long long
using namespace std;
const int maxn=105;
ll getsg(ll x)
{	return x&1?getsg(x>>1):x>>1; }
int main()
{
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		ll sum=0,x;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%lld",&x),sum^=getsg(x);
		puts(sum?"YES":"NO");
	}
}