#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2e4+5;
int f[maxn],w[maxn];
int find(int x)
{
	if(x!=f[x])
	{
		int rt=find(f[x]);
		w[x]+=w[f[x]],f[x]=rt;
	}
	return f[x];
}
int main()
{
	int t,n,u,v;
	char o[3];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++) f[i]=i,w[i]=0;
		while(scanf("%s",o)&&o[0]!='O')
			if(o[0]=='E')
				scanf("%d",&u),find(u),printf("%d\n",w[u]);
			else
				scanf("%d%d",&u,&v),f[u]=v,w[u]=abs(u-v)%1000;
	}
}
