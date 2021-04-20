#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll inf=1e18;
void print(ll x)
{	printf("%lld.%s\n",x/2,x&1?"5":"0"); }
int main()
{
	int n;
	ll d,x,mxv1=-inf,mxv2=-inf,mnv1=inf,mnv2=inf;
	scanf("%d%lld",&n,&d);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&x);
		mxv1=max(mxv1,x+d*i);
		mnv1=min(mnv1,x+d*i);
		mxv2=max(mxv2,x+d*(n-i));
		mnv2=min(mnv2,x+d*(n-i));
	}
	ll tmp1=mxv1-mnv1,tmp2=mxv2-mnv2;
	if(tmp1<tmp2) print(tmp1);
	else print(tmp2);
}