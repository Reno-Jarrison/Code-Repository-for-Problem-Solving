#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int a[maxn];
int main()
{
	int t,n,k;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		int ans=1;
		for(int i=n-1;i;i--,ans++)
			if(a[i+1]-a[i]>k) break;
		printf("%d\n",ans);
	}
}