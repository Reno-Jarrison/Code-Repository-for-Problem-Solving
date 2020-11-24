#include<cstdio>
const int maxn=1e6+5;
using namespace std;
int pcnt,p[maxn],vis[maxn],sp[maxn],sum[maxn];
int main()
{
	for(int i=5;i<maxn;i+=4)
	{
		if(!vis[i]) p[++pcnt]=i;
		for(int j=1;i*p[j]<maxn;j++)
		{
			vis[i*p[j]]=1;
			if(!vis[i]) sp[i*p[j]]=1;
			if(i%p[j]==0) break;
		}
	}
	for(int i=1;i<maxn;i++)
		sum[i]=sum[i-1]+sp[i];
	int n;
	while(scanf("%d",&n)&&n)
		printf("%d %d\n",n,sum[n]);
}