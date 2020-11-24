#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
bool getsg(ll a,ll b)
{
	if(a>b) swap(a,b);
	return b%a==0||b-a>a?true:!getsg(a,b-a);
}
int main()
{
	ll a,b;
	while(~scanf("%lld%lld",&a,&b)&&a&&b)
		printf("%s",getsg(a,b)?"Stan":"Ollie"),puts(" wins");
}