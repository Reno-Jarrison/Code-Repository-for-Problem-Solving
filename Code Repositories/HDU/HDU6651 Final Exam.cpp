#include<cstdio> 
#include<cmath>
#define ll long long
using namespace std;
int main()
{
	ll t,n,m,k;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld%lld",&n,&m,&k);
		printf("%lld\n",(k-1)*(ll)ceil(1.0*(m+1)/(n-k+1))+m+1);
	}
}
