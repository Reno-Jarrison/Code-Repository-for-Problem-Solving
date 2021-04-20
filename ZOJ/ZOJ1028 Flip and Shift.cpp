#include<bits/stdc++.h>
using namespace std;
int cnt[2];
int main()
{
	int t,n,x;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		cnt[0]=cnt[1]=0;
		for(int i=0;i<n;i++)
			scanf("%d",&x),cnt[i&1]+=x;
		if(n&1||abs(cnt[0]-cnt[1])<=1)
			puts("YES");
		else puts("NO");
	}
}