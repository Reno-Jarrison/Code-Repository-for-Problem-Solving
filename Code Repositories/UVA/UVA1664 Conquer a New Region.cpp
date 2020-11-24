#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
const int maxn=2e5+5;
struct edge
{	int u,v,w; }e[maxn];
int f[maxn],cnt[maxn];
ll ans[maxn];
bool operator <(const edge& x,const edge& y)
{	return x.w>y.w; }
int find(int x)
{	return f[x]==x?x:f[x]=find(f[x]); }
int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		for(int i=1;i<=n;i++) f[i]=i,cnt[i]=1,ans[i]=0;
		for(int i=1;i<n;i++)
			scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
		sort(e+1,e+n);
		for(int i=1;i<n;i++)
		{
			int fu=find(e[i].u),fv=find(e[i].v);
			ll uans=ans[fu]+1LL*cnt[fv]*e[i].w;
			ll vans=ans[fv]+1LL*cnt[fu]*e[i].w;
			int fcnt=cnt[fu]+cnt[fv];
			f[fu]=fv;
			int fx=find(e[i].u);
			cnt[fx]=fcnt,ans[fx]=max(uans,vans);
			if(i==n-1) printf("%lld\n",ans[fx]);
		}
	}	
}