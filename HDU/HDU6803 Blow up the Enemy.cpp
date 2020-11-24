#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+5;
int a[maxn],d[maxn];
int main()
{
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d%d",&a[i],&d[i]);
		double ans=0;
		for(int i=1;i<=n;i++)
		{
			double cur=0;
			for(int j=1;j<=n;j++)
			{
				int cnt1=100/a[i],cnt2=100/a[j];
				if(cnt1*a[i]<100) cnt1++;
				if(cnt2*a[j]<100) cnt2++;
				int t1=(cnt1-1)*d[i],t2=(cnt2-1)*d[j];
				if(t1==t2) cur+=0.5;
				else cur+=t1<t2?1:0;
			}
			ans=max(ans,cur/n);
		}
		printf("%.6lf\n",ans);
	}
}