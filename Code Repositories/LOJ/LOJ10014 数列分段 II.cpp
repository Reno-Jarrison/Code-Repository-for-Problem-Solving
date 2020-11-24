#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e5+5;
ll a[maxn];
bool check(ll mval,int lim,int n)
{
	int cnt=1;
	ll sum=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]>mval) return false;
		sum+=a[i];
		if(sum>mval) cnt++,sum=a[i];
	}
	return cnt<=lim;
}
int main()
{
	int n,m;
	cin>>n>>m;
	ll l=1e9,r=0;
	for(int i=1;i<=n;i++) 
		cin>>a[i],r+=a[i],l=min(l,a[i]);
	while(l<=r)
	{
		ll mid=(l+r)>>1;
		if(check(mid,m,n)) r=mid-1;
		else l=mid+1;
	}
	cout<<l;
}