#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod=1e9+7;
const int maxn=455;
ll c[maxn][maxn],base[maxn][maxn],v[maxn][1];
ll mat[maxn][maxn],buf[maxn][maxn];
void init(ll a[maxn][maxn],int n,int val)
{
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			a[i][j]=(i==j?val:0);
}
void qmul(ll a[maxn][maxn],ll b[maxn][maxn],int n)
{
	init(buf,n,0);
	for(int i=0;i<n;i++)
        for(int k=0;k<n;k++) if(a[i][k]) 
            for(int j=0;j<n;j++)
				(buf[i][j]+=a[i][k]*b[k][j])%=mod;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			a[i][j]=buf[i][j];
}
void mqpow(ll k,int n)
{
	init(mat,n,1);
	while(k)
	{
		if(k&1) qmul(mat,base,n);
		qmul(base,base,n),k>>=1;
	}
}
void getc(int n)
{
	c[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		c[i][0]=c[i][i]=1;
		for(int j=1;j<n;j++)
			c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
	}
}
int main()
{
	int t,n;
	getc(450);
	scanf("%d",&t);
	while(t--)
	{
		ll a,r;
		scanf("%d%lld%lld",&n,&a,&r);
		for(int i=0;i<=r+1;i++)
		{
			v[i][0]=0;
			for(int j=0;j<=r+1;j++) 
				base[i][j]=0;
		}
		for(int i=0;i<=r;i++)
			for(int j=0;j<=i;j++)
				base[i][j]=a*c[i][j]%mod;
		for(int i=0;i<=r+1;i++)
			base[i][r+1]=1;
		v[r+1][0]=a;
		mqpow(n,r+2);
		ll ans=0;
		for(int i=0;i<=r+1;i++)
			ans=(ans+mat[r][i]*v[i][0]%mod)%mod;
		printf("%lld\n",ans);
	}
}