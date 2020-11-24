#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	double l,d,ans;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lf%lf",&l,&d);
		ans=l<=d?0:log(l/d)+1;
		printf("%.6lf\n",ans);
	}
}