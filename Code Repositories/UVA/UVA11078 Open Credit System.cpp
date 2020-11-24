#include<bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
int main()
{
	int t,n,x;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		int mxv=-inf,ans=-inf;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&x);
			ans=max(ans,mxv-x);
			mxv=max(mxv,x);
		}
		printf("%d\n",ans);
	}
}