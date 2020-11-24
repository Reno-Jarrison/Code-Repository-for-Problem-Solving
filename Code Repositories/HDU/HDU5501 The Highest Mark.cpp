#include<iostream>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
struct node
{
	ll a,b,c;
	inline void in()
		{ cin>>a>>b>>c; }
	bool operator <(const node &x) const
		{ return c*x.b<b*x.c; }
}a[1005];
ll dp[3005],ans;
int main()
{
	int T,n,t;
	cin>>T;
	while(T--)
	{
		memset(dp,0,sizeof(dp));
		ans=0;
		cin>>n>>t;
		for(int i=1;i<=n;i++)
			a[i].in();
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++)
			for(int j=t;j>=a[i].c;j--)
				dp[j]=max(dp[j],dp[j-a[i].c]+a[i].a-j*a[i].b);
		for(int i=1;i<=t;i++)
			ans=max(ans,dp[i]);
		cout<<ans<<endl;
	}
} 