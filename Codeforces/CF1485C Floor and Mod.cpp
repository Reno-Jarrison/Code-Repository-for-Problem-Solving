#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	int t,x,y;
	scanf("%d",&t);
	while(t--)
	{
		ll ans=0;
		scanf("%d%d",&x,&y),y++;
		int i=2;
		while(i<=y&&x/i>i-2)
			ans+=i-2,i++;
		for(int l=i;l<=min(x,y);l++)
		{
			int r=min(x/(x/l),y);
			ans+=(x/l)*(r-l+1),l=r;
		}
		printf("%lld\n",ans);
	}
}