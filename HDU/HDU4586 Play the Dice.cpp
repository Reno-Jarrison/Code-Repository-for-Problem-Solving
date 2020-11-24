#include<cstdio>
using namespace std;
int main()
{
	int n,m;
	while(~scanf("%d",&n))
	{
		int x,sum=0;
		for(int i=1;i<=n;i++)
			scanf("%d",&x),sum+=x;
		scanf("%d",&m);
		for(int i=1;i<=m;i++)
			scanf("%d",&x);
		if(n==m) printf(sum?"inf\n":"0.00\n");
		else printf("%.2lf\n",(double)sum/(n-m));
	}
}