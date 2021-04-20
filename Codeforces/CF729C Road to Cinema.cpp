#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2e5+5,inf=1e9+5;
int x[maxn],c[maxn],v[maxn],t;
pair<int,int>p[maxn];
bool check(int V,int k)
{
	ll cur=0;
	for(int i=1;i<=k;i++)
	{
		int L=x[i]-x[i-1];
		if(L>V) return false;
		else if(L*2<V) cur+=L;
		else cur+=3LL*L-V;
	}
	return cur<=(ll)t;
}
int main()
{
	int n,k,s;
	scanf("%d%d%d%d",&n,&k,&s,&t);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&c[i],&v[i]);
	for(int i=1;i<=k;i++)
		scanf("%d",&x[i]);
	sort(x+1,x+k+1);
	x[k+1]=s;
	int l=1,r=1e9;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(check(mid,k+1)) r=mid-1;
		else l=mid+1;
	}
	int lim=l,ans=inf;
	for(int i=1;i<=n;i++)
		if(v[i]>=lim) ans=min(ans,c[i]);
	if(ans==inf) ans=-1;
	printf("%d\n",ans);
}