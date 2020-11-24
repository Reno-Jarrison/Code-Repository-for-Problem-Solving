#include<bits/stdc++.h>
#define ll long long
using namespace std;
int sqr(ll x,int mod)
{	
	ll tmp=x*x;
	while(tmp>=mod) tmp/=10;
	return tmp;
}
int main()
{
	int t,n,k;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		int mod=1,pt1=k,pt2=k,ans=k;
		while(n--) mod*=10;
		do
		{
			pt1=sqr(pt1,mod);
			pt2=sqr(pt2,mod);
			ans=max(ans,pt2);
			pt2=sqr(pt2,mod);
			ans=max(ans,pt2);
		}while(pt1!=pt2);
		printf("%d\n",ans);
	}
}