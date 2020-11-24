#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=3e7;
ll ans[maxn+5];
int main()
{
	int t,n,cases=0;
	for(register int c=1;c<=(maxn>>1);c++)
		for(register int a=c*2;a<=maxn;a+=c)
			(a^(a-c))==c?ans[a]++:false;
	for(int i=2;i<=maxn;i++) ans[i]+=ans[i-1]; 
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		printf("Case %d: %lld\n",++cases,ans[n]);
	}
}
