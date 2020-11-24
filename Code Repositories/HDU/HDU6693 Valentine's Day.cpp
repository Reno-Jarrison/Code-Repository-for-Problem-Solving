#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e4+5;
double p[maxn];
int main()
{
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%lf",&p[i]);
		sort(p+1,p+n+1);
		if(p[n]>0.5) { printf("%.8lf\n",p[n]); continue; } 
		double mul=1.0,ans=0,tmp=0;
		for(int i=n;i;i--)
		{
			tmp=tmp*(1-p[i])+mul*p[i];
			mul*=1-p[i];
			if(tmp<ans) break;
			ans=tmp;
		} 
		printf("%.8lf\n",ans);
	}
} 