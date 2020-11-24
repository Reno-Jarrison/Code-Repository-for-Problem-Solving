#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int inf=0x3f3f3f3f;
int dp1[105][15],dp2[105][105][15],sum[105][3];
int getsum(int x,int y,int flag)
{	return sum[y][flag]-sum[x-1][flag]; }
int main()
{
	int n,m,cnt;
	cin>>n>>m>>cnt;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<m;j++)
			cin>>sum[i][j],sum[i][j]+=sum[i-1][j];
		if(m==2) sum[i][2]=sum[i][0]+sum[i][1];
	}
	memset(dp1,-inf,sizeof(dp1));
	memset(dp2,-inf,sizeof(dp2));
	for(int i=0;i<=n;i++)
	{ dp1[i][0]=0; for(int j=0;j<=n;j++) dp2[i][j][0]=0; }
	for(int i=1;i<=n;i++)
		for(int k=1;k<=cnt;k++)
		{
			if(m==1) 
			{
				dp1[i][k]=dp1[i-1][k];
				for(int j=1;j<=i;j++)
					dp1[i][k]=max(dp1[i][k],dp1[j-1][k-1]+getsum(j,i,0));
			}
			else for(int j=1;j<=n;j++)
			{
				int &tmp=dp2[i][j][k];
				tmp=max(dp2[i-1][j][k],dp2[i][j-1][k]);
				for(int d=1;d<=i;d++)
					tmp=max(tmp,dp2[d-1][j][k-1]+getsum(d,i,0));
				for(int d=1;d<=j;d++)
					tmp=max(tmp,dp2[i][d-1][k-1]+getsum(d,j,1));
				for(int d=1;d<=min(i,j);d++)
					tmp=max(tmp,dp2[d-1][d-1][k-1]+getsum(d,min(i,j),2));
			}
		}
	int ans=-inf;
	for(int i=1;i<=n;i++)
	{
		if(m==1) ans=max(ans,dp1[i][cnt]);
		else for(int j=1;j<=n;j++)
			ans=max(ans,dp2[i][j][cnt]);
	}
	cout<<ans;
}