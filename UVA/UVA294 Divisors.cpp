#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		ll l,r,ans,mxv=0;
		scanf("%lld%lld",&l,&r);
		for(ll i=l;i<=r;i++)
		{
			ll tmp=i,cnt=1;
			for(ll i=2;i*i<=tmp;i++)
				if(tmp%i==0)
				{
					ll tot=1;
					while(tmp%i==0)
						tmp/=i,tot++;
					cnt*=tot;
				}
			if(tmp>1) cnt*=2;
			if(cnt>mxv) mxv=cnt,ans=i;
		}
		printf("Between %lld and %lld, %lld has a maximum of %lld divisors.\n",l,r,ans,mxv);
	}
}