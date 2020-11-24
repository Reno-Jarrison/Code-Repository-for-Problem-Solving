#include<cstdio>
#define ll long long
using namespace std;
const int maxn=1e5;
ll phi[maxn+5]={0,1};
int cnt,p[maxn];
void getphi()
{
	for(int i=2;i<=maxn;i++)
	{
		if(!phi[i]) p[++cnt]=i,phi[i]=i-1;
		for(int j=1;i*p[j]<=maxn;j++)
			if(i%p[j]) phi[i*p[j]]=phi[i]*phi[p[j]];
			else { phi[i*p[j]]=phi[i]*p[j]; break; }
	}
}
int main()
{
	getphi();
	ll n,ans=1;
	while(~scanf("%lld",&n)&&n)
	{
		if(n==1) ans=0;
		else if(n<=maxn) ans=phi[n];
		else
		{
			ans=n;
			for(int i=1;p[i]*p[i]<=n&&i<=cnt;i++)
				if(n%p[i]==0)
				{
					ans=ans/p[i]*(p[i]-1);
					while(n%p[i]==0) n/=p[i];
				}
			if(n>1) ans=ans/n*(n-1);
		}
		printf("%lld\n",ans);
	}
}
