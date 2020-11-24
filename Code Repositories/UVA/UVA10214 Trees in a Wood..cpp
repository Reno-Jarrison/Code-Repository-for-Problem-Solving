#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
const int maxn=2e3+5;
int pcnt,p[maxn],phi[maxn]={0,1};
int gcd(int a,int b)
{	return !b?a:gcd(b,a%b); }
int main()
{
	for(int i=2;i<maxn;i++)
	{
		if(!phi[i]) p[++pcnt]=i,phi[i]=i-1;
		for(int j=1;i*p[j]<maxn;j++)
			if(i%p[j]==0)
			{	phi[i*p[j]]=phi[i]*p[j]; break; }
			else phi[i*p[j]]=phi[i]*phi[p[j]];
	}
	int a,b;
	while(scanf("%d%d",&a,&b)&&a)
	{
		ll ans=0;
		for(int i=1;i<=a;i++)
		{
			int q=b/i,r=b%i;
			ans+=1LL*q*phi[i];
			for(int j=1;j<=r;j++)
				if(gcd(i,j)==1) ans++;
		}
		printf("%.7lf\n",4.0*(ans+1)/((2.0*a+1)*(2.0*b+1)-1));
	}
}