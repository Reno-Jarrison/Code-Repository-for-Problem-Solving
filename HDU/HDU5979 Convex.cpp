#include<cstdio>
#include<cmath>
using namespace std;
const double PI=acos(-1);
int main()
{
	int n,d,ang;
	while(~scanf("%d%d",&n,&d))
	{
		double ans=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&ang);
			ans+=0.5*d*d*sin(ang/180.0*PI);
		}
		printf("%.3lf\n",ans);
	}
}