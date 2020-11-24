#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+5,maxm=2e4+5,maxq=5e4+5;
struct query
{	int o,fst,sec; }q[maxq];
int f[maxn],w[maxn],p[maxn],eu[maxm],ev[maxm],ans[maxq];
map<pair<int,int>,int>mp;
int find(int x)
{	return f[x]==x?x:f[x]=find(f[x]); }
int getmax(int a,int b)
{	return (p[a]>p[b]||(p[a]==p[b]&&a<b))?a:b; }
void merge(int u,int v)
{
	int fu=find(u),fv=find(v);
	if(fu!=fv) f[fu]=fv,w[fv]=getmax(w[fv],w[fu]);
}
int main()
{
	int n,m,t,u,v,ks=0;
	while(~scanf("%d",&n))
	{
		if(ks++) puts("");
		for(int i=0;i<n;i++)
			scanf("%d",&p[i]),f[i]=i,w[i]=i;
		scanf("%d",&m);
		for(int i=1;i<=m;i++)
		{
			scanf("%d%d",&eu[i],&ev[i]);
			if(eu[i]>ev[i]) swap(eu[i],ev[i]);
		}
		scanf("%d",&t);
		mp.clear();
		for(int i=1;i<=t;i++)
		{
			char s[10];
			scanf("%s",s);
			if(s[0]=='d')
			{
				scanf("%d%d",&u,&v);
				if(u>v) swap(u,v);
				q[i].o=0,q[i].fst=u,q[i].sec=v;
				mp[make_pair(u,v)]=1;
			}
			else
			{
				scanf("%d",&u);
				q[i].o=1,q[i].fst=u;
			}
		}
		for(int i=1;i<=m;i++)
			if(!mp[make_pair(eu[i],ev[i])])
				merge(eu[i],ev[i]);
		int idx=0;
		for(int i=t;i;i--)
		{
			if(q[i].o)
			{
				int x=q[i].fst,fx=find(x);
				ans[++idx]=(p[w[fx]]>p[x]?w[fx]:-1);
			}
			else merge(q[i].fst,q[i].sec);
		}
		for(int i=idx;i;i--)
			printf("%d\n",ans[i]);
	}	
}