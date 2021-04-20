#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+5;
int x[maxn];
double y[maxn];
double sqr(double x)
{	return x*x; }
int main()
{
	int n,r;
	scanf("%d%d",&n,&r);
	for(int i=1;i<=n;i++)
		scanf("%d",&x[i]);
	for(int i=1;i<=n;i++)
	{
		y[i]=r;
		for(int j=1;j<i;j++)
			if(abs(x[i]-x[j])<=2*r)
				y[i]=max(y[i],y[j]+sqrt(4*r*r-sqr(abs(x[i]-x[j]))));
	}
	for(int i=1;i<=n;i++)
		printf("%.7lf ",y[i]);
}