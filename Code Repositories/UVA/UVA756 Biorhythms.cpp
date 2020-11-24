#include<bits/stdc++.h>
#define ll long long
using namespace std;
int cases=0;
ll M=21252,n[3]={23,28,33},m[3],x[3];
void exgcd(ll a,ll b,ll& x,ll& y)
{
	if(!b) x=1,y=0;
	else exgcd(b,a%b,y,x),y-=a/b*x;
}
int main()
{
	ll p[3],d,y,ans;
	for(int i=0;i<3;i++) 
		m[i]=M/n[i],exgcd(m[i],n[i],x[i],y);
	while(scanf("%lld%lld%lld%lld",&p[0],&p[1],&p[2],&d))
	{
		if(p[0]==-1&&p[1]==-1&&p[2]==-1&&d==-1) break;
		ans=0;
		for(int i=0;i<3;i++)
			ans=(ans+p[i]%n[i]*x[i]*m[i])%M;
		ans=(ans>d?ans-d:ans-d+M);
		printf("Case %d: the next triple peak occurs in %lld days.\n",++cases,ans);
	}
}
