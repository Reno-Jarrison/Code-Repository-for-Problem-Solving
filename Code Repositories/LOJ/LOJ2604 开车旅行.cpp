#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>
#include<iostream>
#define ll long long
using namespace std;
const int maxn=1e5+5,inf=0x7f7f7f7f;
int toa[maxn],tob[maxn];
ll da[maxn],db[maxn];
struct city
{	int id; ll h; }p[maxn];
bool operator <(const city& x,const city& y)
{	return x.h<y.h; }
struct node1
{	ll h; int l1,r1,l2,r2; }list[maxn];
struct node2
{
	int to; ll d,a,b;
	node2(int to=0,ll d=inf,ll a=inf,ll b=inf):
		to(to),d(d),a(a),b(b){}
}dp[maxn][25];
struct node3
{	
	int to; ll d; 
	node3(int to=0,ll d=0):to(to),d(d){}
};
bool operator <(const node3& x,const node3& y)
{	return x.d<y.d||(x.d==y.d&&list[x.to].h<list[y.to].h); }
int dcmp(double x)
{	return fabs(x)<1e-6?0:x<0?-1:1; }
void pretreat(int n)
{
	sort(p+1,p+n+1);
	p[0].h=list[0].h=inf;
	for(int i=1;i<=n;i++)
	{
		node1 tmp;
		tmp.l1=i>1?p[i-1].id:0,tmp.l2=i>2?p[i-2].id:0;
		tmp.r1=i<n?p[i+1].id:0,tmp.r2=i<n-1?p[i+2].id:0;
		tmp.h=p[i].h,list[p[i].id]=tmp;
	}
	for(int i=1;i<=n;i++)
	{
		int l1=list[i].l1,l2=list[i].l2;
		int r1=list[i].r1,r2=list[i].r2;
		ll dl1=l1?abs(list[i].h-list[l1].h):inf;
		ll dr1=r1?abs(list[i].h-list[r1].h):inf;
		ll dl2=l2?abs(list[i].h-list[l2].h):inf;
		ll dr2=r2?abs(list[i].h-list[r2].h):inf;
		vector<node3>v;
		v.push_back(node3(l1,dl1)),v.push_back(node3(l2,dl2));
		v.push_back(node3(r1,dr1)),v.push_back(node3(r2,dr2));
		sort(v.begin(),v.end());
		tob[i]=v[0].to,db[i]=v[0].d;
		toa[i]=v[1].to,da[i]=v[1].d;
		da[i]=abs(list[i].h-list[toa[i]].h);
		db[i]=abs(list[i].h-list[tob[i]].h);
		list[l1].r1=list[l2].r2=r1,list[l1].r2=r2;
		list[r1].l1=list[r2].l2=l1,list[r1].l2=l2;
	}
	for(int i=1;i<=n;i++)
	{
		dp[i][0].to=tob[toa[i]];
		dp[i][0].a=da[i];
		dp[i][0].b=db[toa[i]];
		dp[i][0].d=dp[i][0].a+dp[i][0].b;
	}
	for(int i=1;i<=20;i++)
		for(int j=1;j<=n;j++)
		{
			int mid=dp[j][i-1].to;
			dp[j][i].to=dp[mid][i-1].to;
			dp[j][i].a=dp[j][i-1].a+dp[mid][i-1].a;
			dp[j][i].b=dp[j][i-1].b+dp[mid][i-1].b;
			dp[j][i].d=dp[j][i-1].d+dp[mid][i-1].d;
		}
}
void getans(int s,ll x,ll& d1,ll& d2)
{
	d1=d2=0;
	for(int i=20;i>=0;i--)
		if(x>=dp[s][i].d)
		{
			x-=dp[s][i].d;
			d1+=dp[s][i].a;
			d2+=dp[s][i].b;
			s=dp[s][i].to;
		}
	if(x>=dp[s][0].a) d1+=dp[s][0].a;
}
int main()
{
	int n,m,s,s0=0;
	ll x0,x,d1,d2;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",&p[i].h),p[i].id=i;
	pretreat(n);
	scanf("%lld",&x0);
	double tmp=(double)inf;
	for(int i=1;i<=n;i++)
	{
		bool flag=false;
		getans(i,x0,d1,d2);
		double q=d2?(double)d1/d2:(double)inf;
		if(dcmp(q-tmp)<0) tmp=q,s0=i;
		else if(dcmp(q-tmp)==0&&p[i].h<p[s0].h) s0=i; 
	}
	printf("%d\n",s0);
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%lld",&s,&x);
		getans(s,x,d1,d2);
		printf("%lld %lld\n",d1,d2);
	}
}