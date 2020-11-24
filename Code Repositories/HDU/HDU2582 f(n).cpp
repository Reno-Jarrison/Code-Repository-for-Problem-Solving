#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e6+5;
int p[maxn],n;
ll ans[maxn];
void init(int n)
{
	for(int i=2;i<=n;i++)
	{
		if(p[i]) continue;
		p[i]=i;
		for(int j=2*p[i];j<=n;j+=p[i])
			p[j]=(!p[j]?i:1);
	}
	ans[3]=p[3];
	for(int i=4;i<=n;i++)
		ans[i]=ans[i-1]+p[i];
}
int main()
{
	init(1e6);
	while(~scanf("%d",&n))
		printf("%lld\n",ans[n]);
}