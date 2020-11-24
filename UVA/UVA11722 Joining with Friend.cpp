#include<cstdio>
#define area(x) ((x)*(x)*1.0/2)
using namespace std;
int main()
{
	int t,t1,t2,s1,s2,w,cases=0;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d%d%d",&t1,&t2,&s1,&s2,&w);
		double a1=(s2-s1)*(t2-t1),a2=0;
		int p1=s1+w,p2=t2-w;
		if(p1<t2)
		{
			a2+=area(t2-p1);
			if(p1<t1) a2-=area(t1-p1);
			if(p2>s2) a2-=area(p2-s2);
		}
		int q1=s2-w,q2=t1+w;
		if(q1>t1)
		{
			a2+=area(q1-t1);
			if(q1>t2) a2-=area(t2-q1);
			if(q2<s1) a2-=area(s1-q2);
		}
		if(p1<t1+s1-s2||q1>t2+s2-s1) a2=a1;
		printf("Case #%d: %.8lf\n",++cases,(a1-a2)/a1);
	}
}