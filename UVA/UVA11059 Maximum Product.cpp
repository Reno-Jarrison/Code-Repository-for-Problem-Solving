#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	int n,ks=0;
	while(~scanf("%d",&n))
	{
		ll ans=0,s[20];
		for(int i=1;i<=n;i++)
			scanf("%lld",&s[i]);
		for(int i=1;i<=n;i++)
			for(int j=i;j<=n;j++)
			{
				ll tmp=1;
				for(int k=i;k<=j;k++) tmp*=s[k];
				ans=max(ans,tmp);
			}
		printf("Case #%d: The maximum product is %lld.\n",++ks,ans);
		puts("");
	}
}