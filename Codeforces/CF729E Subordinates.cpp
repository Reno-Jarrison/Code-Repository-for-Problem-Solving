#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int cnt[maxn];
int main()
{
	int n,s,a,ans=0,cur=1;
	scanf("%d%d",&n,&s);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a);
		if(i==s) ans=a>0;
		else cnt[a]++;
	}
	for(int i=1;i<=n-1;i++)
	{
		ans+=cnt[i]==0,cur+=max(cnt[i],1);
		if(cur>=n) break;
	}
	printf("%d\n",ans);
}