#include<cstdio> 
#define ll long long
using namespace std;
ll gcd(ll a,ll b)
{	return !b?a:gcd(b,a%b); }
ll f(ll n,ll m)
{
	ll pt=0,k=n;
	while(pt<m)
	{
		k++;
		if(gcd(n,k)==1) pt++;
	}	
	return k;	
}
int main()
{
	int t,m,bit=10,maxb=1<<(bit+1);
	scanf("%d",&t);
	while(t--)
	{
		ll k,base,ans=-1;
		scanf("%lld%d",&k,&m);
		base=(k>>bit)<<bit;
		for(int i=1;i<maxb;i++)
		{
			ll n=base+i;
			if((f(n,m)-n)==(n^k))
			{	ans=n; break; }
		}
		printf("%lld\n",ans);
	}
}
