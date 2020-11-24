#include<cstdio>
#define lowbit(x) (x)&(-x)
#define ll long long
using namespace std;
const int maxn=5e3+5;
ll tree[maxn][maxn];
void update(int x,int y,ll val,int n,int m)
{
	int y0=y;
	while(x<=n)
	{
		while(y<=m) tree[x][y]+=val,y+=lowbit(y);
		x+=lowbit(x),y=y0;
	}
}
ll query(int x,int y)
{
	int y0=y; ll ans=0;
	while(x)
	{
		while(y) ans+=tree[x][y],y-=lowbit(y);
		x-=lowbit(x),y=y0;
	}
	return ans;
}
ll getsum(int x1,int y1,int x2,int y2)
{	return query(x2,y2)+query(x1-1,y1-1)-query(x1-1,y2)-query(x2,y1-1); }
int main()
{
	int n,m,o,x1,y1,x2,y2;
	ll x;
	scanf("%d%d",&n,&m);
	while(~scanf("%d",&o))
	{
		if(o==1) scanf("%d%d%lld",&x1,&y1,&x),update(x1,y1,x,n,m);
		if(o==2)
		{
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			printf("%lld\n",getsum(x1,y1,x2,y2));
		}
	}
}