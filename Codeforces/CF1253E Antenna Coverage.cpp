#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
struct node
{
	int x,s;
	friend bool operator <(const node& a,const node& b)
	{	return a.x<b.x||(a.x==b.x&&a.s<b.s); }
}p[100];
int dp[maxn];
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>p[i].x>>p[i].s;
	sort(p+1,p+n+1);
	for(int i=1;i<=m;i++) dp[i]=i;
	for(int i=1;i<=n;i++)
	{
		int l=max(1,p[i].x-p[i].s),r=min(m,p[i].x+p[i].s),cost=0;		
		for(int j=l;j<=r;j++) dp[j]=min(dp[j],dp[l-1]);
		while(r<m) l--,r++,cost++,dp[r]=min(dp[r],dp[max(0,l-1)]+cost);
	}
	cout<<dp[m];
}
