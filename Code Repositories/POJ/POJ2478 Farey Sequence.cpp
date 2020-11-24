#include<cstdio>
#define ll long long
using namespace std;
const int maxn=1e6;
int cnt,p[maxn+5],phi[maxn+5];
ll sum[maxn+5];
void getphi()
{
	for(int i=2;i<=maxn;i++)
	{
		if(!phi[i]) p[++cnt]=i,phi[i]=i-1;
		for(int j=1;i*p[j]<=maxn;j++)
			if(i%p[j]) phi[i*p[j]]=phi[i]*phi[p[j]];
			else {	phi[i*p[j]]=phi[i]*p[j]; break; }
	}
}
int main()
{
	getphi();
	for(int i=2;i<=maxn;i++)
		sum[i]=sum[i-1]+phi[i];
	int n;
	while(scanf("%d",&n)!=EOF&&n)
		printf("%lld\n",sum[n]);
}
