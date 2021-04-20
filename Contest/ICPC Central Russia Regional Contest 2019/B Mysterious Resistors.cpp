#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+5;
const double eps=1e-7;
int r[maxn];
bool check(int k,double val,double R)
{
	double res=0;
	for(int i=1;i<=k;i++)
		res+=1.0/(1.0/r[i]+1.0/val);
	return res>=R;
}
int main()
{
	int k,R,cnt=100;
	scanf("%d%d",&k,&R);
	for(int i=1;i<=k;i++)
		scanf("%d",&r[i]);
	double l=0,r=1e6;
	while(r-l>eps&&cnt)
	{
		double mid=(l+r)/2;
		if(check(k,mid,R)) r=mid;
		else l=mid;
		cnt--;
	}
	printf("%.6lf\n",l);
}