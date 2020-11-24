#include<cstdio>
#define ll long long
#define lowbit(x) (x)&(-x)
using namespace std;
const int maxn=5e3+5;
ll tree1[maxn][maxn],tree2[maxn][maxn],tree3[maxn][maxn],tree4[maxn][maxn],delta;
void update(int x,int y,ll val,int n,int m)
{
	for(int i=x;i<=n;i+=lowbit(i))
		for(int j=y;j<=m;j+=lowbit(j))
			tree1[i][j]+=val,tree2[i][j]+=val*x,tree3[i][j]+=val*y,tree4[i][j]+=val*x*y;
}
ll query(int x,int y)
{
	ll ans=0;
	for(int i=x;i;i-=lowbit(i))
		for(int j=y;j;j-=lowbit(j))
			ans+=tree1[i][j]*(x+1)*(y+1)+tree4[i][j]-tree2[i][j]*(y+1)-tree3[i][j]*(x+1);
	return ans;
}
void modify(int x1,int y1,int x2,int y2,ll val,int n,int m)
{
	update(x1,y1,val,n,m),update(x2+1,y2+1,val,n,m);
	update(x1,y2+1,-val,n,m),update(x2+1,y1,-val,n,m);
}
ll getsum(int x1,int y1,int x2,int y2)
{	return query(x2,y2)+query(x1-1,y1-1)-query(x1-1,y2)-query(x2,y1-1); }
int main()
{
	int n,m,o,x1,y1,x2,y2;
	scanf("%d%d",&n,&m);
	while(~scanf("%d",&o))
	{
		if(o==1) 
		{
			scanf("%d%d%d%d%lld",&x1,&y1,&x2,&y2,&delta);
			modify(x1,y1,x2,y2,delta,n,m);
		}
		if(o==2)
		{
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			printf("%lld\n",getsum(x1,y1,x2,y2));
		}
	}
}