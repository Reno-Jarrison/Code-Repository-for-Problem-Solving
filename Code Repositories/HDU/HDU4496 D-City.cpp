#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+5,maxm=1e5+5;
int f[maxn],ans[maxm],eu[maxm],ev[maxm];
int find(int x)
{	return f[x]==x?x:f[x]=find(f[x]); }
int main()
{
	int n,m;
	while(~scanf("%d%d",&n,&m))
	{
		for(int i=0;i<n;i++) f[i]=i;
		for(int i=1;i<=m;i++)
			scanf("%d%d",&eu[i],&ev[i]);
		int cnt=n;
		for(int i=m;i;i--)
		{
			ans[i]=cnt;
			int fu=find(eu[i]),fv=find(ev[i]);
			if(fu!=fv) f[fu]=fv,cnt--;
		}
		for(int i=1;i<=m;i++)
			printf("%d\n",ans[i]);
	}
}