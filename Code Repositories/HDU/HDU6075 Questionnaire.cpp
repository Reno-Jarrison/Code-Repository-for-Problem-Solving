#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t,n,x;
	scanf("%d",&t);
	while(t--)
	{
		int cnt[2]={0},ans;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&x),cnt[x%2]++;
		ans=(cnt[1]>cnt[0]);
		printf("%d %d\n",2,ans);
	}
}