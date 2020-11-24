#include<bits/stdc++.h>
using namespace std;
const double G=6.6743e-11;
int main()
{
	int t,a,b,t0;
	scanf("%d",&t);
	while(t--)
	{
		double va=0,vb=0,d;
		scanf("%d%d%lf%d",&a,&b,&d,&t0),d*=1e3;
		for(int i=1;i<=t0;i++)
		{
			double f=G*a*b/d/d;
			double a1=f/a,a2=f/b;
			double d1=va+0.5*a1,d2=vb+0.5*a2;
			va+=a1,vb+=a2,d-=d1+d2;
		}
		printf("%.7lf\n",d/1e3);
	}
}