#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e5+5;
int a[maxn];
int main()
{
	int t,n,m;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		int l=1,r=n,ans=0;
		while(l<=r)
		{
			if(l<r&&a[l]+a[r]<=m) l++;
			r--,ans++; 
		}
		printf("%d\n",ans);
		if(t) puts("");
	}
}