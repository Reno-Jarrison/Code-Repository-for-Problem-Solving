#include<bits/stdc++.h>
using namespace std;
const int maxn=2e6+5;
int f[maxn],vis[maxn];
int find(int x)
{	return x==f[x]?x:f[x]=find(f[x]); }
int build(int x)
{	return vis[x]=0,f[x]=x; }
int main()
{
	int n,m,u,v,x,ks=0;
	char s[3];
	while(scanf("%d%d",&n,&m)&&n)
	{
		int idx=n;
		for(int i=1;i<=n;i++) f[i]=build(++idx),vis[i]=0;
		for(int i=1;i<=m;i++)
		{
			scanf("%s",s);
			if(s[0]=='M')
			{
				scanf("%d%d",&u,&v);
				int fu=find(u+1),fv=find(v+1);
				if(fu!=fv) f[fu]=fv;
			}
			if(s[0]=='S')
				scanf("%d",&x),f[x+1]=build(++idx);
		}
		int ans=0;
		for(int i=1;i<=n;i++)
			if(!vis[find(i)]) 
				vis[find(i)]=1,ans++;
		printf("Case #%d: %d\n",++ks,ans);
	}

}