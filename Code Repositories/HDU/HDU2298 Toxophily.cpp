#include<bits/stdc++.h>
using namespace std;
const double PI=acos(-1),eps=1e-8;
double x,y,v;
double f(double a)
{	return x*tan(a)-9.8/2.0*x*x/v/v/cos(a)/cos(a); }
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lf%lf%lf",&x,&y,&v);
		if(x<eps)
		{
			if(v*v/(2.0*9.8)<y) puts("-1");
			else printf("%.6lf\n",PI/2);
			continue;
		}
		double l=0,r=PI/2;
		for(int i=1;r-l>eps&&i<=200;i++)
		{
			double lmid=(r-l)/3+l,rmid=(r-l)/3+lmid;
			f(lmid)>f(rmid)?r=rmid:l=lmid;
		}
		if(f(r)<y)
		{	puts("-1"); continue; }
		l=0;
		for(int i=1;r-l>eps&&i<=200;i++)
		{
			double mid=(l+r)/2.0;
			f(mid)>y?r=mid:l=mid;
		}
		printf("%.6lf\n",l);
	}
}