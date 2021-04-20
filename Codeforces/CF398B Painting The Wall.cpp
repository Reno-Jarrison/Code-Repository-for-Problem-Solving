#include<bits/stdc++.h>
using namespace std;
const int maxn=2e3+5;
bool visr[maxn],visc[maxn];
double dp[maxn][maxn];
int main()
{
	int n,m,r,c;
	scanf("%d%d",&n,&m);
	int x=0,y=0;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&r,&c);
		if(!visr[r]) 
			visr[r]=1,x++;
		if(!visc[c]) 
			visc[c]=1,y++;
	}
	dp[n][n]=0;
	for(int i=n;i>=x;i--)
		for(int j=n;j>=y;j--)
		{
			if(i==n&&j==n) continue;
			dp[i][j]+=dp[i+1][j]*(n-i)*j;
			dp[i][j]+=dp[i][j+1]*i*(n-j);
			dp[i][j]+=dp[i+1][j+1]*(n-i)*(n-j);
			dp[i][j]=(dp[i][j]+n*n)/(n*n-i*j);
		}
	printf("%.4lf\n",dp[x][y]);
}