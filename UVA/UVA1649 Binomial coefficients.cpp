#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n;
int check(ll mval,ll k)
{
	ll ans=1;
	for(int i=1;i<=k;i++)
	{
		if(ans/i>n/(mval-i+1)) return 1;
		ans=ans*(mval-i+1)/i;
	}
	return ans==n?0:-1;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld",&n);
		set<pair<ll,ll>>ans;
		for(int i=1;i<=30;i++)
		{
			ll l=i,r=n;
			while(l<=r)
			{
				ll mid=(l+r)>>1;
				int tag=check(mid,i);
				if(!tag)
				{
					ans.insert(make_pair(mid,i));
					ans.insert(make_pair(mid,mid-i));
					break;
				}
				else if(tag>0) r=mid-1;
				else l=mid+1;
			}
		}
		int cnt=ans.size();
		printf("%d\n",cnt);
		for(pair<ll,ll> x:ans)
			printf("(%lld,%lld)%c",x.first,x.second,--cnt?' ':'\n');
	}
}
