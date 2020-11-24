#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=1e9+7;
int main()
{
	int n,x,pos;
	scanf("%d%d%d",&n,&x,&pos);
	int l=0,r=n,cntl=0,cntg=0;
	while(l<r)
	{
		int mid=(l+r)>>1;
		if(pos<mid) r=mid,cntg++;
		else 
		{
			l=mid+1;
			if(pos>mid) cntl++;
		}
	}
	ll ans=1;
	for(int i=n-x;i>=n-x-cntg+1;i--) 
		ans=ans*i%mod;
	for(int i=x-1;i>=x-1-cntl+1;i--) 
		ans=ans*i%mod;
	for(int i=n-cntl-cntg-1;i;i--) 
		ans=ans*i%mod;
	printf("%lld\n",ans);
}