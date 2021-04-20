#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e6+5;
ll a,b,c,s[maxn],dp[maxn];
int que[maxn];
ll X(int t) { return s[t]; }
ll Y(int t) { return dp[t]+a*s[t]*s[t]-b*s[t]; }
double slope(int a,int b)
{	return 1.0*(Y(a)-Y(b))/(X(a)-X(b)); }
void solve(int n)
{
	int head=1,tail=0;
	que[++tail]=0;
	for(int i=1;i<=n;i++)
	{
		ll k=2LL*a*s[i];
		while(head<tail&&slope(que[head],que[head+1])>k) head++;
		int j=que[head];
		dp[i]=dp[j]+a*(s[i]-s[j])*(s[i]-s[j])+b*(s[i]-s[j])+c;
		while(head<tail&&slope(i,que[tail])>slope(i,que[tail-1])) tail--;
		que[++tail]=i;
	}
}
int main()
{
	int n;
	scanf("%d%lld%lld%lld",&n,&a,&b,&c);
	for(int i=1;i<=n;i++)
		scanf("%lld",&s[i]),s[i]+=s[i-1];
	solve(n);
	printf("%lld\n",dp[n]);
}