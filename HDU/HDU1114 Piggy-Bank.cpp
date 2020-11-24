#include<iostream>
#include<cstring>
#define ll long long
#define Maxn 0x3f3f3f3f
using namespace std;
struct COIN
{
	int p,w;
}coin[505];
int dp[10005],last;
int main()
{
	ios::sync_with_stdio(false);
	int t,e,f,n;
	cin>>t;
	while(t--)
	{
		cin>>e>>f>>n;
		f-=e;
		for(int i=1;i<=n;i++)
			cin>>coin[i].p>>coin[i].w;
		for(int i=1;i<=f;i++) dp[i]=Maxn;
		dp[0]=0;
		for(int i=1;i<=n;i++)
			for(int j=coin[i].w;j<=f;j++)
				dp[j]=min(dp[j],dp[j-coin[i].w]+coin[i].p);
		if(dp[f]==Maxn) cout<<"This is impossible."<<endl;
		else cout<<"The minimum amount of money in the piggy-bank is "<<dp[f]<<'.'<<endl;
	}
 } 