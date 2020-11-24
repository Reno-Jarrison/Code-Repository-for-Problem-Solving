#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;
int a[10005];
int main()
{
	int n,m,x,ks=0;
	while(scanf("%d%d",&n,&m)&&n&&m)
	{
		printf("CASE# %d:\n",++ks);
		map<int,int>mp;
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		for(int i=n;i;i--) mp[a[i]]=i;
		while(m--)
		{
			scanf("%d",&x);
			if(mp[x]) printf("%d found at %d\n",x,mp[x]);
			else printf("%d not found\n",x);
		}
	}
}