#include<cstdio>
#define ll long long
#define lowbit(x) ((x)&(-x))
using namespace std;
const int maxn=1e3+5;
ll tree[2][2][maxn][maxn],delta;
void update(int x,int y,ll val,int n,int m)
{
	for(int i=x;i<=n;i+=lowbit(i))
		for(int j=y;j<=m;j+=lowbit(j))
			tree[x&1][y&1][i][j]^=val;
}
ll query(int x,int y)
{
	ll ans=0;
	for(int i=x;i;i-=lowbit(i))
		for(int j=y;j;j-=lowbit(j))
			ans^=tree[x&1][y&1][i][j];
	return ans;
}
void modify(int x1,int y1,int x2,int y2,int val,int n,int m)
{
	update(x1,y1,val,n,m),update(x2+1,y2+1,val,n,m);
	update(x1,y2+1,val,n,m),update(x2+1,y1,val,n,m);
}
ll getsum(int x1,int y1,int x2,int y2)
{	return query(x1-1,y1-1)^query(x2,y2)^query(x1-1,y2)^query(x2,y1-1); }
int main()
{
	int n,m,q,o,x1,y1,x2,y2;
	scanf("%d%d",&n,&q),m=n;
	for(int i=1;i<=q;i++)
	{
		scanf("%d",&o);
		if(o==2)
		{
			scanf("%d%d%d%d%lld",&x1,&y1,&x2,&y2,&delta);
			modify(x1,y1,x2,y2,delta,n,m);
		}
		if(o==1)
		{
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			printf("%lld\n",getsum(x1,y1,x2,y2));
		}
	}
}
