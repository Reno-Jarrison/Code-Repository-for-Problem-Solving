#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
#define maxn 405 
using namespace std;
int a[maxn],sum[maxn],dpmax[maxn][maxn],dpmin[maxn][maxn];
int main()
{
	int n,maxm=-inf,minm=inf;
	scanf("%d",&n);
	memset(dpmax,-inf,sizeof(dpmax));
	memset(dpmin,inf,sizeof(dpmin));
	for(int i=1;i<=n;i++) 
		scanf("%d",&a[i]),a[i+n]=a[i];
	for(int i=1;i<=n<<1;i++) 
		sum[i]=sum[i-1]+a[i],dpmax[i][i]=dpmin[i][i]=0; 
	for(int i=2;i<=n;i++)
		for(int l=1,r=l+i-1;r<=n*2;l++,r++)
		{
			int w=sum[r]-sum[l-1];
			for(int mid=l;mid<r;mid++)
			{
				dpmax[l][r]=max(dpmax[l][r],dpmax[l][mid]+dpmax[mid+1][r]+w);
				dpmin[l][r]=min(dpmin[l][r],dpmin[l][mid]+dpmin[mid+1][r]+w);
			}
		}
	for(int i=1;i<=n;i++)
		maxm=max(maxm,dpmax[i][i+n-1]),minm=min(minm,dpmin[i][i+n-1]);
	printf("%d\n%d",minm,maxm);
}
	