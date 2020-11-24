#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e3+5;
int p[maxn];
int main()
{
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&p[i]);
		sort(p+1,p+n+1);
		int pt=(n&1?1:2),nim=0;
		while(pt<=n)
			nim^=p[pt]-p[pt-1]-1,pt+=2;
		printf("%s will win\n",nim?"Georgia":"Bob");
	}
}