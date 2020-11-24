#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
const int maxn=1e5+5;
const double eps=1e-8;
int x[maxn],y[maxn],n;
int dcmp(double x)
{
	if(abs(x)<eps) return 0;
	else return x>0?1:-1;
}
bool check(double R)
{
	double l=-1e14,r=1e14;
	for(int i=1;i<=n;i++)
	{
		double d=2.0*y[i]*R-1.0*y[i]*y[i];
		if(dcmp(d)<0) return false;
		else if(dcmp(d)==0) d=0;
		else d=sqrt(d);
		l=max(l,x[i]-d),r=min(r,x[i]+d);
	}
	return dcmp(l-r)<=0;
}
int main()
{
	int ok=1,neg=0,pos=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&x[i],&y[i]);
		if(y[i]>0) pos=1;
		if(y[i]<0) neg=1,y[i]=-y[i];
	}
	if(pos&&neg) ok=0;
	if(!ok) { printf("-1"); return 0; }
	double l=0,r=1e14;
	int cnt=0;
	while(dcmp(r-l)>0)
	{
		if(++cnt>300) break;
		double m=(l+r)/2.0;
		if(check(m)) r=m-1e-7;
		else l=m+1e-7;
	}
	printf("%.6lf",l);
}