#include<cstdio>
#include<cstring>
#include<set>
#define ll long long 
using namespace std;
const int maxn=1e6+5;
ll a,b,ans[200],tmp[200],x;
set<ll>s;
ll gcd(ll x,ll y)
{	return !y?x:gcd(y,x%y); }
bool dfs(ll c,ll d,int las,int dep,int lim)
{
	if(dep==lim)
	{
		if(c>1||d==las||s.count(d)) return false;
		tmp[dep]=d;
		int ok=0;
		for(int i=dep;i>=0;i--)
			if(tmp[i]==ans[i]) continue;
			else if(tmp[i]<ans[i])  { ok=1; break; }
			else break;
		if(ok) for(int i=0;i<=dep;i++)
			ans[i]=tmp[i];
		return true;
	}
	ll e=max(int(d/c),las+1),ok=0;
	while(true)
	{
		if(s.count(e)) { e++; continue; }
		if(c*e>d*(lim-dep+1)) break;
		ll cx=c*e-d,dx=d*e,g=gcd(cx,dx);
		cx/=g,dx/=g;
		if(cx<0||dx<0) { e++; continue; }
		tmp[dep]=e,ok|=dfs(cx,dx,e++,dep+1,lim);
	}
	return ok;
}
int idastar()
{
	int lim=0;
	while(true)
	{
		memset(ans,0x3f3f3f3f,sizeof(ans));
		if(dfs(a,b,0,0,lim++)) break;
	}
	return lim;
}
int main()
{
	int t,k,ks=0;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld%lld%d",&a,&b,&k);
		s.clear();
		for(int i=0;i<k;i++) 
			scanf("%lld",&x),s.insert(x);
		ll g=gcd(a,b);
		a/=g,b/=g;
		int n=idastar();
		printf("Case %d: %lld/%lld=",++ks,a,b);
		for(int i=0;i<n;i++)
			printf("1/%lld%c",ans[i],i==n-1?'\n':'+');
	}
}
