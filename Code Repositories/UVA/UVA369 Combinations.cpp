#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=105;
ll C[maxn][maxn];
void init(int n)
{
	C[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		C[i][0]=C[i][i]=1;
		for(int j=1;j<i;j++)
			C[i][j]=C[i-1][j-1]+C[i-1][j];
	}
}
int main()
{
	init(100);
	int n,m;
	while(scanf("%d%d",&n,&m)&&n)
		printf("%d things taken %d at a time is %lld exactly.\n",n,m,C[n][m]);
}