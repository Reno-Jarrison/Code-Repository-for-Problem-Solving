#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll inf=1e18;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n,k,l1,r1,l2,r2,ans=0;
		cin>>n>>k>>l1>>r1>>l2>>r2;
		if(l1>l2||(l1==l2&&r1>r2))
			swap(l1,l2),swap(r1,r2);
		if(l2<=r1)
		{
			ll a=min(r1,r2)-l2,b=max(r1,r2)-l1,res=b-a;
			k=max(0LL,k-a*n);
			ll cnt=res?min(k/res,n):n;
			k-=res*cnt,ans=res*cnt;
			ans+=(cnt<n?k:k*2);
		}
		else
		{
			ll a=l2-r1,b=r2-l1;
			ll cnt=min(k/b,n);
			k-=b*cnt,ans=(a+b)*cnt;
			ans+=min((cnt?k*2:inf),(cnt<n?a+k:inf));
		}
		cout<<ans<<endl;
	}
}