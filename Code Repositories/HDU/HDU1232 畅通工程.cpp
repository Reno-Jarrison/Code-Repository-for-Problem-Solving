#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+5;
int f[maxn];
int find(int x)
{	return f[x]==x?x:f[x]=find(f[x]); }
int main()
{
	int n,m,u,v;
	while(scanf("%d",&n)&&n)
	{
		scanf("%d",&m);
		for(int i=1;i<=n;i++) f[i]=i;
		int cnt=n;
		for(int i=1;i<=m;i++)
		{
			scanf("%d%d",&u,&v);
			int fu=find(u),fv=find(v);
			if(fu!=fv) f[fu]=fv,cnt--;
		}
		printf("%d\n",cnt-1);
	}
}