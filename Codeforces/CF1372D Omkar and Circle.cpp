#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2e5+5;
ll a[maxn<<1],pre[maxn<<1];
ll sum(int l,int r)
{	return l<=2?pre[r]:pre[r]-pre[l-2]; }
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]),a[i+n]=a[i];
	for(int i=1;i<=n*2;i++)
		pre[i]=(i>1?pre[i-2]:0)+a[i];
	ll ans=0;
	for(int i=n;i<n*2;i++)
		ans=max(ans,max(sum(i-n+1,i),sum(i-n+2,i-1)));
	printf("%lld\n",ans);
}