#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=8e3+5;
int sum[maxn];
int main()
{
	int n,k,x;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&x),sum[x]++;	
	sort(sum+1,sum+k+1,greater<int>());
	ll ans=1e12;
	for(int i=1;i<=k;i++)
	{
		int cnt=0,mxv=sum[1];
		for(int l=i,r=k;l<=r;l++,r--,cnt++)
			if(l<r) mxv=max(mxv,sum[l]+sum[r]);
		ans=min(ans,1LL*((k-i)/2+i)*mxv);
	}
	printf("%lld\n",ans);
}