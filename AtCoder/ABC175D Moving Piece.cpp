#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=5e3+5;
int nxt[maxn][35];
ll c[maxn],sum[maxn][35],mxs[maxn][35];
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&nxt[i][0]);
	for(int i=1;i<=n;i++)
		scanf("%lld",&sum[i][0]),mxs[i][0]=sum[i][0];
	ll ans=-1e15;
	for(int j=1;j<=30;j++)
		for(int i=1;i<=n;i++)
		{
			nxt[i][j]=nxt[nxt[i][j-1]][j-1];
			sum[i][j]=sum[i][j-1]+sum[nxt[i][j-1]][j-1];
			mxs[i][j]=max(mxs[i][j-1],sum[i][j-1]+mxs[nxt[i][j-1]][j-1]);
		}
	for(int i=1;i<=n;i++)
	{
		int pt=i,cnt=k; ll s=0;
		for(int j=30;~j;j--)
		{
			if((1<<j)>cnt) continue;
			ans=max(ans,s+mxs[pt][j]);
			s+=sum[pt][j],pt=nxt[pt][j],cnt-=(1<<j);
		}
	}
	printf("%lld\n",ans);
}