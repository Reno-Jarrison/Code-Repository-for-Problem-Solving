#include<bits/stdc++.h>
#define ld long double
using namespace std;
const int maxn=1e7+5;
unsigned long long seed;
long double gen()
{
	static const long double Z=(long double)1.0/(1LL<<32);
	seed>>=16;
	seed&=(1ULL<<32)-1;
	seed*=seed;
	return seed*Z;
}
int main()
{
	int t,n,ks=0;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%llu",&n,&seed);
		ld sum1=0,sum2=0;
		for(int i=1;i<=n;i++)
		{
			ld x=gen();
			sum1+=x,sum2+=x*x;
		}
		ld m=sum1/n;
		printf("Case #%d: %.5Lf\n",++ks,sqrt(sum2/n-m*m));
	}
}