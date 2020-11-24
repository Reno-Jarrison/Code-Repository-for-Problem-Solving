#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,k,ans;
bool check(ll mval)
{
	ll cnt=0,x=1;
	if((mval&1)==0) mval>>=1,cnt--;
	while(x*(mval+1)<n)
		cnt+=x,x<<=1;
	cnt+=max(0LL,n-x*mval+1);
	return cnt>=k;
}
int main()
{
	cin>>n>>k;
	for(int i=0;i<=1;i++) 
	{
		ll l=0,r=n>>1;
		while(l<=r)
		{
			ll mid=(l+r)>>1;
			if(check(mid<<1|i)) l=mid+1;
			else r=mid-1;
		}
		ans=max(ans,r<<1|i);
	}
	cout<<ans;
}
