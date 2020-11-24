#include<cstdio>
#define ll long long
using namespace std;
const int maxn=5e4,maxm=6e3;
int cnt,prime[maxm],phi[maxn+5],sum[maxn+5];
void pretreat()
{
	for(int i=2;i<=maxn;i++)
	{
		if(!phi[i]) prime[++cnt]=i,phi[i]=i-1;
		for(int j=1;i*prime[j]<=maxn;j++)
			if(i%prime[j]) phi[i*prime[j]]=phi[i]*phi[prime[j]];
			else { phi[i*prime[j]]=phi[i]*prime[j]; break; }
		sum[i]=sum[i-1]+phi[i];
	}
}
int main()
{
	pretreat();
	int n;
	while(scanf("%d",&n)&&n)
		printf("%d\n",sum[n]*2+1);
}