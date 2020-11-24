#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod=1e6+7;
int c[405][505];
void getc(int n,int m)
{
	for(int i=0;i<=n;i++)
	{
		c[i][0]=c[i][i]=1;
		for(int j=1;j<i;j++)
			c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
	}
}
int main()
{
	getc(400,500);
	int t,n,m,k,ks=0;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&n,&m,&k);
		ll ans=0;
		for(int i=0;i<(1<<4);i++)
		{
			int a=0,b=0,cnt=0;
			if(i&1) a++,cnt++;
			if(i&2) a++,cnt++;
			if(i&4) b++,cnt++;
			if(i&8) b++,cnt++;
			ans=(ans+c[(n-a)*(m-b)][k]*(cnt&1?-1:1)+mod)%mod;
		}
		printf("Case %d: %lld\n",++ks,ans);
	}
}