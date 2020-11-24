#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
const int maxn=1e5+5;
const double eps=1e-7;
int dcmp(double x)
{	return fabs(x)<eps?0:x>0?1:-1; }
struct node
{
	double l,r;
	friend bool operator <(const node& x,const node& y)
	{	return x.r<y.r||(!dcmp(x.r-y.r)&&dcmp(x.l-y.l)<0); }	
}p[maxn];
int main()
{
	int n; double L,D,px,py;
	while(~scanf("%lf%lf%d",&L,&D,&n))
	{
		for(int i=1;i<=n;i++)
		{
			scanf("%lf%lf",&px,&py);
			double d=sqrt(D*D-py*py);
			p[i].l=max(0.0,px-d),p[i].r=min(L,px+d);
		}
		sort(p+1,p+n+1);
		double pt=-1.0;
		int ans=0;
		for(int i=1;i<=n;i++)
			if(dcmp(p[i].l-pt)>0) pt=p[i].r,ans++;
		printf("%d\n",ans);
	}
}