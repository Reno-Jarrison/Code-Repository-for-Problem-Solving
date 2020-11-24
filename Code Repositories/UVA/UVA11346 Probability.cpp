#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
	int t;
	double a,b,s,ans;
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		scanf("%lf%lf%lf",&a,&b,&s);
		if(s==0.0) ans=a*b;
		else if(s/b>=a) ans=0;
		else ans=a*b+s*(log(s/b)-log(a)-1.0);
		printf("%.6lf%%\n",ans/a/b*100.0);
	}
}