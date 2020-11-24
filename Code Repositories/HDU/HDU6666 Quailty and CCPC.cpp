#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e5+5;
struct node
{
	char s[15];
	int p,t;	
}a[maxn];
bool operator <(const node& x,const node& y)
{	return x.p>y.p||(x.p==y.p&&x.t<y.t); }
int main()
{
	int T,n,d;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&d);
		for(int i=1;i<=n;i++)
			scanf("%s%d%d",a[i].s,&a[i].p,&a[i].t);
		if(d*n%10!=5)
		{	puts("Quailty is very great"); continue; } 
		sort(a+1,a+n+1);
		printf("%s\n",a[d*n/10+1].s); 
	} 
}
