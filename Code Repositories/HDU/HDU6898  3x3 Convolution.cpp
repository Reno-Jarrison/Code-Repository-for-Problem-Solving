#include<bits/stdc++.h>
using namespace std;
int a[55][55];
int main()
{
	int t,n,x;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				scanf("%d",&a[i][j]);
		int tag,tot=0;
		for(int i=1;i<=3;i++)
			for(int j=1;j<=3;j++)
			{
				scanf("%d",&x),tot+=x;
				if(i==1&&j==1) tag=x;
			}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				printf("%d%c",tag==tot?a[i][j]:0,j==n?'\n':' ');
	}
}