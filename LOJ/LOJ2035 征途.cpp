#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=3e3+5;
ll s[maxn],dp[maxn][2];
int que[maxn],tag;
ll Y(int t) { return dp[t][!tag]+s[t]*s[t]; }
ll X(int t) { return s[t]; }
double slope(int a,int b)
{	return 1.0*(Y(a)-Y(b))/(X(a)-X(b)); }
int main()
{
	int n,m,x;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x),s[i]=s[i-1]+x;
		dp[i][tag]=s[i]*s[i];
	}
	for(int it=1;it<m;it++)
	{
		int head=1,tail=0;
		que[++tail]=0,tag^=1;
		for(int i=1;i<=n;i++)
		{
			ll k=2*s[i];
			while(head<tail&&slope(que[head],que[head+1])<=k) head++;
			int j=que[head];
			dp[i][tag]=dp[j][!tag]+(s[i]-s[j])*(s[i]-s[j]);
			while(head<tail&&slope(que[tail],i)<slope(que[tail-1],i)) tail--;
			que[++tail]=i;
		}
	}
	printf("%lld",m*dp[n][tag]-s[n]*s[n]);
}