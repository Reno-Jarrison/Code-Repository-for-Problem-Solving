#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e6+5;
ll a[maxn],s[maxn],avg;
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]),avg+=a[i];
	avg/=n;
	for(int i=1;i<=n;i++)
		a[i]-=avg,s[i]=s[i-1]+a[i];
	sort(s+1,s+n+1);
	ll med=s[(n+1)>>1],ans=0;
	for(int i=1;i<=n;i++)
		ans+=abs(s[i]-med);
	printf("%lld\n",ans);
}