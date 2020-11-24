#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
const int maxn=5e6+5,mod=1e7;
ull a[maxn],b[maxn],p1[maxn],p2[maxn],k1,k2;
ull gen()
{
	ull k3=k1,k4=k2;
	k1=k4,k3^=(k3<<23),k2=k3^k4^(k3>>17)^(k4>>26);
	return k2+k4;
}
void init(int n)
{
	for(int i=1;i<=n;i++)
		a[i]=gen()%mod+1,b[i]=gen()%mod+1;
}
int main()
{
	int n,m;
	while(~scanf("%d%d%lld%lld",&n,&m,&k1,&k2))
	{
		init(n);
		for(int i=1;i<=n;i++)
			p1[i]=a[i],p2[i]=a[i]+b[i];
		sort(p1+1,p1+n+1,greater<ull>());
		sort(p2+1,p2+n+1,greater<ull>());
		int pt1=1,pt2=1;
		ull ans=0,cur=0;
		for(int i=1;i<=min(3*n,m);i++)
		{
			if(pt1>n||(pt1>1&&pt2<=n&&p2[pt2]>p1[pt1]+p1[pt1-1]))
				cur+=p2[pt2++]-p1[--pt1];
			else cur+=p1[pt1++];
			ans^=cur;
		}
		printf("%lld\n",ans);
	}
}