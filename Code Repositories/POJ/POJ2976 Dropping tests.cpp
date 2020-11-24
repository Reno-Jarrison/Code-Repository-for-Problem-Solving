#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e3+5;
const double eps=1e-4;
int a[maxn],b[maxn],n,k;
double tmp[maxn];
bool check(double mval)
{
	for(int i=1;i<=n;i++)
		tmp[i]=a[i]-mval*b[i];
	sort(tmp+1,tmp+n+1);
	double ans=0;
	for(int i=n;i>k;i--) ans+=tmp[i];
	return ans>=0;
}
int main()
{
	while(scanf("%d%d",&n,&k)&&n)
	{
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for(int i=1;i<=n;i++)
			scanf("%d",&b[i]);
		double l=0,r=1;
		while(r-l>eps)
		{
			double mid=(l+r)/2;
			check(mid)?l=mid:r=mid;
		}
		printf("%.0lf\n",l*100);
	}
}