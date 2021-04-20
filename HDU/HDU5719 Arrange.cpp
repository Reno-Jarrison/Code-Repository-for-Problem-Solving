#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e5+5,mod=998244353;
int l[maxn],r[maxn];
int main()
{
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&l[i]);
		for(int i=1;i<=n;i++)
			scanf("%d",&r[i]);
		ll ans=l[1]==r[1];
		for(int i=2;i<=n;i++)
		{
			if(l[i]>l[i-1]||r[i]<r[i-1]) ans=0;
			if(l[i]<l[i-1]&&r[i]>r[i-1]) ans=0;
			if(r[i]-l[i]+1<i) ans=0;
			if(l[i]==l[i-1]&&r[i]==r[i-1])
				ans=ans*(r[i]-l[i]+1-i+1)%mod;
		}
		if(l[n]>1||r[n]<n) ans=0;
		printf("%lld\n",ans);
	}
}