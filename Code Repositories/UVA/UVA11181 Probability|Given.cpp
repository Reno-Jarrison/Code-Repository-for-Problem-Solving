#include<cstdio>
#include<cstring> 
using namespace std;
double p[25],q[25],sum;
int main()
{
	int n,r,cases=0;
	while(scanf("%d%d",&n,&r)&&n)
	{
		for(int i=0;i<n;i++)
			scanf("%lf",&p[i]);
		sum=0,memset(q,0,sizeof(q));
		for(int i=0;i<(1<<n);i++)
		{
			int cnt=0;
			double s=1.0;
			for(int j=0;j<n;j++)
				if(i&(1<<j)) s*=p[j],cnt++;
				else s*=1-p[j]; 
			if(cnt!=r) continue;
			sum+=s;
			for(int j=0;j<n;j++)
				if(i&(1<<j)) q[j]+=s;
		}
		printf("Case %d:\n",++cases);
		for(int i=0;i<n;i++)
			printf("%.6lf\n",q[i]/sum);
	}
}