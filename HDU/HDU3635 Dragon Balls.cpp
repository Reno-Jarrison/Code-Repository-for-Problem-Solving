#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+5;
int f[maxn],siz[maxn],w[maxn];
int find(int x)
{
	if(f[x]==x) return x;
	int fx=find(f[x]);
	w[x]+=w[f[x]];
	return f[x]=fx;
}
int main()
{
	int t,n,q,u,v,x,ks=0;
	scanf("%d",&t);
	while(t--)
	{
		printf("Case %d:\n",++ks);
		scanf("%d%d",&n,&q);
		for(int i=1;i<=n;i++)
			f[i]=i,siz[i]=1,w[i]=0;
		while(q--)
		{
			char s[2];
			scanf("%s",s);
			if(s[0]=='T')
			{
				scanf("%d%d",&u,&v);
				int fu=find(u),fv=find(v);
				f[fu]=fv,siz[fv]+=siz[fu],w[fu]++;
			}
			else 
			{
				scanf("%d",&x);
				int fx=find(x);
				printf("%d %d %d\n",fx,siz[fx],w[x]);
			}
		}
	}
}