#include<cstdio>
using namespace std;
const int maxn=1e3+5;
int a[maxn],dpl[maxn][maxn],dpr[maxn][maxn];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]),dpl[i][i]=dpr[i][i]=a[i];
		for(int i=2;i<=n;i++)
			for(int l=1,r=l+i-1;r<=n;l++,r++)
			{
				int lr=dpl[l][r-1],rr=dpr[l][r-1],xr=a[r];
				if(rr==xr) dpl[l][r]=0;
				else if(lr==xr) dpl[l][r]=xr+1;
				else if(xr<rr&&xr<lr) dpl[l][r]=xr;
				else if(rr<xr&&xr<lr) dpl[l][r]=xr-1;
				else if(lr<xr&&xr<rr) dpl[l][r]=xr+1;
				else dpl[l][r]=xr;
				int ll=dpl[l+1][r],rl=dpr[l+1][r],xl=a[l];
				if(ll==xl) dpr[l][r]=0;
				else if(rl==xl) dpr[l][r]=xl+1;
				else if(xl<ll&&xl<rl) dpr[l][r]=xl;
				else if(ll<xl&&xl<rl) dpr[l][r]=xl-1;
				else if(rl<xl&&xl<ll) dpr[l][r]=xl+1;
				else dpr[l][r]=xl;
			}
		printf("%d\n",!(a[1]==dpl[2][n]));
	}
}