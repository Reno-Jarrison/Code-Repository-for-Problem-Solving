#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e6+5;
ll s1[maxn],s2[maxn],dp[maxn];
int que[maxn],d[maxn],p[maxn],c[maxn];
ll X(int t) { return s1[t]; }
ll Y(int t) { return dp[t]+s2[t]; }
double slope(int a,int b)
{	return 1.0*(Y(a)-Y(b))/(X(a)-X(b)); }
void solve(int n)
{
	int head=1,tail=0;
	que[++tail]=0;
	for(int i=1;i<=n;i++)
	{
		ll k=d[i];
		while(head<tail&&slope(que[head],que[head+1])<=k) head++;
		int j=que[head];
		dp[i]=dp[j]+(s1[i]-s1[j])*d[i]-(s2[i]-s2[j])+c[i];
		while(head<tail&&slope(i,que[tail])<slope(i,que[tail-1])) tail--;
		que[++tail]=i;
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&d[i],&p[i],&c[i]);
		s1[i]=s1[i-1]+p[i];
		s2[i]=s2[i-1]+1LL*p[i]*d[i];
	}
	solve(n);
	printf("%lld\n",dp[n]);
}