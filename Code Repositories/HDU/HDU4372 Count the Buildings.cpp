#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=4e3+5,mod=1e9+7;
ll fac[maxn],s[maxn][maxn],c[maxn][maxn];
void init(int n)
{
	fac[0]=c[0][0]=s[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		fac[i]=fac[i-1]*i%mod;
		c[i][0]=c[i][i]=1,s[i][0]=0;
		for(int j=1;j<i;j++)
			c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
		for(int j=1;j<=i;j++)
			s[i][j]=(s[i-1][j-1]+s[i-1][j]*(i-1))%mod;
	}
}
int main()
{
	init(2000);
	int T,n,f,b;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&n,&f,&b);
		printf("%lld\n",s[n-1][f+b-2]*c[b+f-2][f-1]%mod);
	}
}