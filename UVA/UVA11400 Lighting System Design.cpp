#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+5;
struct node
{	int v,k,c,l; }p[maxn];
bool operator <(const node& x,const node& y)
{	return x.v<y.v; }
int dp[maxn],sum[maxn];
int getsum(int l,int r)
{	return sum[r]-sum[l-1]; }
int main()
{
	int n;
	while(scanf("%d",&n)&&n)
	{
		for(int i=1;i<=n;i++)
			scanf("%d%d%d%d",&p[i].v,&p[i].k,&p[i].c,&p[i].l);
		sort(p+1,p+n+1);
		for(int i=1;i<=n;i++) sum[i]=sum[i-1]+p[i].l;
		memset(dp,0x3f,sizeof(dp)),dp[0]=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=i;j++)
				dp[i]=min(dp[i],dp[j-1]+p[i].c*getsum(j,i)+p[i].k);
		printf("%d\n",dp[n]);
	}
}