#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[15],b[15];
void exgcd(ll a,ll b,ll& d,ll& x,ll& y)
{
	if(!b) d=a,x=1,y=0;
	else exgcd(b,a%b,d,y,x),y-=a/b*x;
}
int main()
{
	int n;
	ll ans=0,lcm=1,m,d,x,y;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld%lld",&a[i],&b[i]),lcm*=a[i];
	for(int i=1;i<=n;i++)
	{
		m=lcm/a[i];
		exgcd(m,a[i],d,x,y);
		ans=(ans+b[i]*m*x)%lcm;
	}
	printf("%lld",(ans+lcm)%lcm);
} 