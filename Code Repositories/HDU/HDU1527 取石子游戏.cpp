#include<cstdio>
#include<cmath>
#include<algorithm>
#define ll long long
using namespace std;
const double phi=(1+sqrt(5))/2;
int main()
{
    ll a,b;
    while(~scanf("%lld%lld",&a,&b))
    {
        ll delta=phi*abs(a-b);
        puts(delta==min(a,b)?"0":"1");
    }
}