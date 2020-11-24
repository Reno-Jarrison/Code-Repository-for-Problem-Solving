#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=5e4+5;
int cnt,p[maxn],vis[maxn];
void getprime()
{
	for(int i=2;i<=maxn-5;i++)
	{
		if(!vis[i]) p[++cnt]=i;
		for(int j=1;p[j]*i<=maxn-5;j++)
		{
			vis[p[j]*i]=1;
			if(i%p[j]==0) break;
		}
	}
}
int main()
{
	ll n,cases=0;
	getprime();
	while(scanf("%lld",&n)!=EOF&&n)
	{
		int ans=0,tot=0;
		if(n==1) ans=2;
		else for(int i=1;i<=cnt&&n>1;i++)
		{
			int mul=1,flag=0;
			while(n%p[i]==0)
				n/=p[i],mul*=p[i],flag=true;
			flag?ans+=mul,tot++:false;
		}
		if(n>1) ans+=n,tot++;
		if(tot==1) ans++;
		printf("Case %d: %lld\n",++cases,ans);
	}
}
