#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=505,mod=1e8+7;
int t,n,k,b,r;
struct point
{	
	point(int x=0,int y=0):x(x),y(y){}
	int x,y;
}p[maxn];
bool operator <(const point& a,const point& b)
{	return a.x<b.x||(a.x==b.x&&a.y<b.y); }
set<point>s;
ll qmul(ll a,ll b,ll p)
{
	ll ans=0;
	while(b)
	{
		if(b&1) (ans+=a)%=p;
		(a+=a)%=p,b>>=1;
	}
	return ans;
}
ll qpow(ll a,ll b,ll p)
{
	ll ans=1;
	while(b)
	{
		if(b&1) ans=qmul(ans,a,p);
		a=qmul(a,a,p),b>>=1;
	}
	return ans;
}
ll inv(ll a,ll p)
{	return qpow(a,p-2,p); }
ll bsgs(ll a,ll b,ll c)
{
	if(c==1&&!b) return 0;
	if(!a) return b?-1:1;
	unordered_map<ll,ll>h;
	ll m=ceil(sqrt(c)),am=qpow(a,m,c);
	for(ll i=0,val=b;i<=m;i++)
		h[val]=i,val=val*a%c;
	for(ll i=1,val=am;i<=m+1;i++)
	{
		if(h[val]) return ((i*m-h[val])%c+c)%c;		
		val=val*am%c;
	}
	return -1;
}
ll solve(ll tmp,int lim)
{
	if(tmp==r) return lim;
	int cnt=0;
	for(int i=0;i<b;i++)
		if(p[i].x==lim) cnt++;
	lim++;
	tmp=qmul(tmp,qpow(k,cnt,mod),mod);
	tmp=qmul(tmp,qpow(k-1,n-cnt,mod),mod);
	if(tmp==r) return lim;
	return bsgs(qpow(k-1,n,mod),qmul(r,inv(tmp,mod),mod),mod)+lim;
}
int main()
{
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		s.clear();
		scanf("%d%d%d%d",&n,&k,&b,&r);
		int limit=1,cnt=n;
		for(int i=0;i<b;i++)
		{
			scanf("%d%d",&p[i].x,&p[i].y);
			limit=max(limit,p[i].x);
			s.insert(p[i]); 
		}
		for(int i=0;i<b;i++)
			if(p[i].x!=limit&&!s.count(point((p[i].x)+1,p[i].y))) cnt++;
		for(int i=0;i<b;i++) if(p[i].x==1) cnt--;
		ll tmp=qmul(qpow(k,cnt,mod),qpow(k-1,(ll)limit*n-b-cnt,mod),mod);
		printf("Case %d: %lld\n",i,solve(tmp,limit));
	}
}
