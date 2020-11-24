#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int f[maxn],siz[maxn];
int find(int x)
{	return f[x]==x?x:f[x]=find(f[x]); }
int main()
{
	int n,m,u,v,ans=1;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) 
		f[i]=i,siz[i]=1;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&u,&v);
		int fu=find(u),fv=find(v);
		if(fu==fv) continue;
		f[fv]=fu,siz[fu]+=siz[fv];
		ans=max(ans,siz[fu]);
	}
	printf("%d\n",ans);
}