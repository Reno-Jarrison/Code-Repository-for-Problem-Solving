#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e5+5,mod=1e9+7;
int f[maxn],tag[maxn],w[maxn],bit[30];
vector<int>vec[maxn];
int find(int x)
{	return f[x]==x?x:f[x]=find(f[x]); }
int main()
{
	int T,n,m,u,v;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
			scanf("%d",&w[i]),f[i]=i,tag[i]=0,vec[i].clear();
		for(int i=1;i<=m;i++)
		{
			scanf("%d%d",&u,&v);
			int fu=find(u),fv=find(v);
			if(fu!=fv) f[fu]=fv;
		}
		int idx=0;
		for(int i=1;i<=n;i++)
		{
			int fx=find(i);
			if(!tag[fx]) tag[fx]=++idx;
			vec[tag[fx]].push_back(w[i]);
		}
		ll ans=0;
		for(int i=1;i<=idx;i++)
		{
			sort(vec[i].begin(),vec[i].end());
			memset(bit,0,sizeof(bit));
			for(int x:vec[i])
			{
				int cur=x;
				for(int j=0;cur&&j<30;j++,cur>>=1)
				{
					if(!(cur&1)) continue;
					ans=(ans+1LL*bit[j]*x%mod*(1<<j))%mod;
					bit[j]++;
				}
			}
		}
		printf("%lld\n",ans);
	}
}