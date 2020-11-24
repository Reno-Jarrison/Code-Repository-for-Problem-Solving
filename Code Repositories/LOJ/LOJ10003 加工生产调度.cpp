#include<iostream>
#include<algorithm>
#define ll long long
#define maxn 1005
using namespace std;
struct node
{
	ll a,b;
	int d,id;
	bool operator <(const node &x) const
	{
		if(d!=x.d) return d<x.d;
		return d>0?b>x.b:a<x.a;
	}
}p[maxn];
ll ta,tb;
int main()
{
	int n;
	scanf("%d",&n);
	for(register int i=1;i<=n;i++)
		scanf("%lld",&p[i].a);
	for(register int i=1;i<=n;i++)
	{
		scanf("%lld",&p[i].b),p[i].d=0,p[i].id=i;
		if(p[i].a<p[i].b) p[i].d=-1;
		else p[i].d=1;
	}
	sort(p+1,p+n+1);
	for(register int i=1;i<=n;i++)
	{
		ta+=p[i].a;
		if(tb<ta) tb=ta;
		tb+=p[i].b;
	}
	printf("%lld\n",tb);
	for(register int i=1;i<=n;i++)
		printf("%d ",p[i].id);
} 