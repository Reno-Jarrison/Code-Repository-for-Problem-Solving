#include<bits/stdc++.h>
using namespace std;
const int maxn=3e4+5;
int f[maxn],w[maxn],siz[maxn];
int find(int x)
{	
	if(f[x]==x) return x;
	int fx=find(f[x]);
	w[x]+=w[f[x]];
	return f[x]=fx;
}
int main()
{
	for(int i=0;i<maxn;i++)
		f[i]=i,siz[i]=1,w[i]=0;
	int q,u,v,x;
	char o[3];
	scanf("%d",&q);
	while(q--)
	{
		scanf("%s",o);
		if(o[0]=='M') 
		{
			scanf("%d%d",&u,&v);
			int fu=find(u),fv=find(v);
			if(fu==fv) continue;
			f[fu]=fv,w[fu]+=siz[fv],siz[fv]+=siz[fu];
		}
		if(o[0]=='C')
		{
			scanf("%d",&x),find(x);
			printf("%d\n",w[x]);
		}
	}
}