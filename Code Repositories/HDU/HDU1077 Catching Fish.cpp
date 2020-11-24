#include<bits/stdc++.h>
using namespace std;
const int maxn=305;
const double eps=1e-6;
double x[maxn],y[maxn];
double sqr(double a)
{	return a*a; }
double dis(int a,int b)
{	return sqrt(sqr(x[a]-x[b])+sqr(y[a]-y[b])); }
int main()
{
	int T,n;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%lf%lf",&x[i],&y[i]);
		int ans=1;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
			{
				double d=dis(i,j);
				if(d-2>0) continue;
				double h=sqrt(1.0-d*d/4.0),dx=x[i]-x[j],dy=y[i]-y[j];
				double px=dx/d,py=dy/d;
				double mx=(x[i]+x[j])/2,my=(y[i]+y[j])/2;
				x[n+1]=mx+h*py,y[n+1]=my-h*px;
				x[n+2]=mx-h*py,y[n+2]=my+h*px;
				int cnt1=0,cnt2=0;
				for(int k=1;k<=n;k++)
				{
					if(dis(k,n+1)<=1+eps) cnt1++;
					if(dis(k,n+2)<=1+eps) cnt2++;
				}
				ans=max(ans,max(cnt1,cnt2));
			}
		printf("%d\n",ans);
	}
}