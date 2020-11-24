#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct point
{
	int x,y;
	point(int x,int y):x(x),y(y){}
};
bool operator <(const point& a,const point& b)
{	return a.x<b.x||(a.x==b.x&&a.y<b.y); }
multiset<point>::iterator it,idx;
ll sqr(ll x) { return x*x; }
int main()
{
	int t,n,ax,bx,cx,ay,by,cy;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d%d%d%d%d",&n,&ax,&bx,&cx,&ay,&by,&cy);
		int x=bx%cx,y=by%cy;
		multiset<point>st;
		st.insert(point(x,y));
		ll ans=0,mnv=1e12;
		for(int i=2;i<=n;i++)
		{
			x=(1LL*x*ax+bx)%cx;
			y=(1LL*y*ay+by)%cy;
			idx=st.lower_bound(point(x,y));
			for(it=idx;it!=st.end();it++)
			{
				int sx=it->x,sy=it->y;
				ll dif=x-sx,dis=sqr(sx-x)+sqr(sy-y);
				if(dif*dif>=mnv) break;
				mnv=min(mnv,dis);
			}
			for(it=idx;it!=st.begin();)
			{
				it--;
				int sx=it->x,sy=it->y;
				ll dif=x-sx,dis=sqr(sx-x)+sqr(sy-y);
				if(dif*dif>=mnv) break;
				mnv=min(mnv,dis);
			}
			st.insert(point(x,y));	
			ans+=mnv;
		}
		printf("%lld\n",ans);
	}
}