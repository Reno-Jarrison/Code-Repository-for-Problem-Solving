#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	int n,x,mxv=0;
	ll ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		mxv=max(mxv,x);
		ans+=mxv-x;
	}
	printf("%lld\n",ans);
}