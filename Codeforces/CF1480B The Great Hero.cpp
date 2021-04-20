#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e5+5;
pair<int,int>p[maxn];
int main()
{
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		ll A,B;
		scanf("%lld%lld%d",&A,&B,&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&p[i].first);
		for(int i=1;i<=n;i++)
			scanf("%d",&p[i].second);
		for(int i=1;i<=n;i++)
		{
			int a=p[i].first,b=p[i].second;
			ll x=b/A-(b%A==0);
			B-=x*a;
		}
		sort(p+1,p+n+1);
		for(int i=1;i<n;i++)
			B-=p[i].first;
		puts(B>0?"YES":"NO");
	}
}