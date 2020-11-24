#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+5;
int a[55],b[maxn];
int main()
{
	int t,n,m;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(int i=0;i<=m;i++)
			scanf("%d",&b[i]);
		int pt=1;
		for(int i=1;i<=n;i++)
			for(int j=pt;j<=m;j++) if(b[j])
			{
				for(int k=j;k<=m;k++)
					b[k]-=b[k-j];
				a[i]=j,pt=j;
				break;
			}
		for(int i=1;i<=n;i++)
			printf("%d%c",a[i],i==n?'\n':' ');
	}
}