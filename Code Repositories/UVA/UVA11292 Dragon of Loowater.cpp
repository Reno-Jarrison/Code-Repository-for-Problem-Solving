#include<bits/stdc++.h>
using namespace std;
const int maxn=2e4+5;
int h[maxn],k[maxn];
int main()
{
	int n,m;
	while(scanf("%d%d",&n,&m)&&n)
	{
		for(int i=1;i<=n;i++)
			scanf("%d",&h[i]);
		for(int i=1;i<=m;i++)
			scanf("%d",&k[i]);
		sort(h+1,h+n+1);
		sort(k+1,k+m+1);
		int pth=1,ptk=1,ans=0;
		while(pth<=n&&ptk<=m)
		{
			while(k[ptk]<h[pth]) ptk++;
			ans+=k[ptk++],pth++;
		}
		if(pth<=n) puts("Loowater is doomed!");
		else printf("%d\n",ans);
	}
}