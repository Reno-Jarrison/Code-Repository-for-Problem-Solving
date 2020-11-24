#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll qpow(ll a,ll b)
{
	ll ans=1;
	while(b)
	{
		if(b&1) ans=ans*a;
		a=a*a,b>>=1;
	}
	return ans;
}
int main()
{
	int t,n,tmp;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n),tmp=n;
		ll ans=1;
		for(int i=2;i*i<=tmp;i++)
			if(tmp%i==0)
			{
				int cnt=1;
				while(tmp%i==0) cnt++,tmp/=i;
				ans*=(qpow(i,cnt)-1)/(i-1);
			}
		if(tmp>1) ans*=(1+tmp);
		printf("%lld\n",ans-n);
	}
}