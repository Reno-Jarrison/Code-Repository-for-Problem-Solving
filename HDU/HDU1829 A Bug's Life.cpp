#include<bits/stdc++.h>
using namespace std;
const int maxn=4e3+5;
int f[maxn];
int find(int x)
{	return f[x]==x?x:f[x]=find(f[x]); }
void merge(int u,int v)
{
	int fu=find(u),fv=find(v);
	if(fu!=fv) f[fu]=fv;
}
int main()
{
	int t,n,m,u,v,ks=0;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++) f[i]=i,f[i+n]=i+n;
		int ok=1;
		for(int i=1;i<=m;i++)
		{
			scanf("%d%d",&u,&v);
			if(find(u)==find(v)||find(u+n)==find(v+n)) ok=0;
			merge(u,v+n),merge(v,u+n);
		}
		printf("Scenario #%d:\n",++ks);
		printf("%suspicious bugs found!\n",ok?"No s":"S");
		puts("");
	}
}