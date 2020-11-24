#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
const int maxn=1e5+5;
ll a[maxn];
int main()
{
	int t,n,m;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
			if(!a[i]) cnt++;
		}
		ll sum=0,mnv=0x7fffffff;
		int pt=1,tot=0;
		while(pt<=n&&tot<m-cnt)
		{
			if(a[pt]) sum+=a[pt],tot++;
			pt++;
		}
		while(pt<=n)
		{
			if(a[pt]) mnv=min(mnv,a[pt]);
			pt++;
		}
		if(cnt>m) puts("Impossible");
		else if(n==m) puts("Richman");
		else printf("%lld\n",sum+mnv-1);		
	}
}