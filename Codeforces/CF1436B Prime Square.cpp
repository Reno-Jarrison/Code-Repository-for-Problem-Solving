#include<bits/stdc++.h>
using namespace std;
const int maxn=105;
int ans[maxn][maxn];
int main()
{
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		memset(ans,0,sizeof(ans));
		for(int i=0;i<n;i++)
			for(int j=0;j<=1;j++)
				ans[i][(i+j)%n]=1;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				printf("%d%c",ans[i][j],j==n-1?'\n':' ');
	}
}