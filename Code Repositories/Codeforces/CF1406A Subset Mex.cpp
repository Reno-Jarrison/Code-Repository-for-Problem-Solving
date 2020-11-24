#include<bits/stdc++.h>
using namespace std;
const int maxn=105;
int cnt[maxn];
int main()
{
	int t,n,x;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		memset(cnt,0,sizeof(cnt));
		for(int i=1;i<=n;i++)
			scanf("%d",&x),cnt[x]++;
		int ans=0,ok=1;
		for(int i=0;i<=101;i++)
		{
			if(ok&&cnt[i]>=2) ans+=2;
			else if(cnt[i]>=1) ok=0,ans++;
			else break;
		}
		printf("%d\n",ans);
	}
}