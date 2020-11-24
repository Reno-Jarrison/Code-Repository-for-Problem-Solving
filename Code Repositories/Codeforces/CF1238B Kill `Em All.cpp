#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e5+5;
ll x[maxn];
int main()
{
	int q,n,r;
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d%d",&n,&r);
		for(int i=1;i<=n;i++)
			scanf("%lld",&x[i]);
		sort(x+1,x+n+1);
		int ans=0;
		for(int i=n;i;i--)
		{
			if(i<n&&x[i]==x[i+1]) continue;	
			if(x[i]>1LL*ans*r) ans++;
		}
		printf("%d\n",ans);
	}
}

