#include<bits/stdc++.h>
#define maxn 100005
#define ll long long
using namespace std;
ll a[maxn],q[maxn],dp[maxn],sum;
bool check(int i,int j)
{
	if(!i) return false;
	return a[j]+dp[j-1]<=a[i]+dp[i-1]; 
}
int main()
{
	int n,k,t=0,h=1;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]),sum+=a[i];
	q[++t]=0;
	for(int i=1;i<=n;i++)
	{
		if(h<=t&&q[h]<i-k) h++;
		while(h<=t&&check(q[t],i)) t--;
		q[++t]=i;
		dp[i]=q[h]?a[q[h]]+dp[q[h]-1]:0;
	}
	printf("%lld",sum-dp[n]);
}