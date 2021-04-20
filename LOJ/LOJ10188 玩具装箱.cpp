#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=5e4+5;
ll s[maxn],dp[maxn],L;
int que[maxn];
ll X(int t) { return s[t]+L; }
ll Y(int t) { return dp[t]+(s[t]+L)*(s[t]+L); }
double slope(int a,int b)
{	return 1.0*(Y(a)-Y(b))/(X(a)-X(b)); }
void solve(int n)
{
	int head=1,tail=0;
	que[++tail]=0;
	for(int i=1;i<=n;i++)
	{
		ll k=2LL*s[i];
		while(head<tail&&slope(que[head],que[head+1])<=k) head++;
		int j=que[head];
		dp[i]=dp[j]+(s[i]-s[j]-L)*(s[i]-s[j]-L);
		while(head<tail&&slope(i,que[tail])<slope(i,que[tail-1])) tail--;
		que[++tail]=i;
	}
}
int main()
{
	int n; ll tmp;
	scanf("%d%lld",&n,&L),L++;
	for(int i=1;i<=n;i++)
		scanf("%lld",&tmp),s[i]=s[i-1]+tmp+1;
	solve(n);
	printf("%lld\n",dp[n]);
}