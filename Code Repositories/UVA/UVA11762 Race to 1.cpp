#include<cstdio>
using namespace std;
const int maxn=1e6,maxm=1e5;
double dp[maxn+5];
int cnt,vis[maxn+5],prime[maxm];
void pretreat()
{
	for(int i=2;i<=maxn;i++)
	{
		if(!vis[i]) 
		{
			prime[++cnt]=i,dp[i]=cnt;
			for(int j=2;j*i<=maxn;j++) vis[j*i]++;
		}
		else 
		{
			int tmp=i,num=0;
			for(int j=1;j<=cnt&&1LL*prime[j]*prime[j]<=i;j++)
				if(tmp%prime[j]==0)
				{
					dp[i]+=dp[i/prime[j]],num++;
					while(tmp%prime[j]==0) tmp/=prime[j];
				}
			if(tmp>1) dp[i]+=dp[i/tmp],num++;
			dp[i]=(dp[i]+cnt)/num;
		}
	}
}
int main()
{
	int t,n,cases=0;
	pretreat();
	scanf("%d",&t);
	while(t--)
		scanf("%d",&n),printf("Case %d: %.10lf\n",++cases,dp[n]);
}