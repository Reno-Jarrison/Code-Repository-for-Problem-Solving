#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=4e3+5;
ll a[maxn],b[maxn],c[maxn],d[maxn];
int main()
{
	int t,n,fst=1;
	scanf("%d",&t);
	while(t--)
	{
		int ans=0;
		unordered_map<ll,int>mp;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%lld%lld%lld%lld",&a[i],&b[i],&c[i],&d[i]);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				mp[a[i]+b[j]]++;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
		 		ans+=mp[-c[i]-d[j]];
		fst?fst=false:puts("");
		printf("%d\n",ans);
	}
}