#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[15];
int gcd(int a,int b)
{	return !b?a:gcd(b,a%b); }
int lcm(int a,int b)
{	return a/gcd(a,b)*b; }
int main()
{
	int n; ll m;
	while(~scanf("%d%lld",&n,&m))
	{
		for(int i=0;i<n;i++)
			scanf("%d",&a[i]);
		ll ans=0;
		for(int i=1;i<(1<<n);i++)
		{
			int cur=i,tmp=1,cnt=0;
			for(int j=0;j<n;j++,cur>>=1)
				if(cur&1) tmp=lcm(tmp,a[j]),cnt++;
			ans+=m/tmp*(cnt&1?1:-1);
		}
		printf("%lld\n",ans);
	}
}