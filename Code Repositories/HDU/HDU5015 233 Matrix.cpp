#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=15,mod=1e7+7;
struct Matrix
{
	int r,c;
	ll num[maxn][maxn];
	Matrix(int r=0,int c=0):r(r),c(c)
	{	memset(num,0,sizeof(num)); }
	void init(int val=0)
	{
		for(int i=0;i<r;i++)
			for(int j=0;j<c;j++)
				num[i][j]=(i==j?val:0);
	}
	ll* operator [](int x)
	{	return num[x]; }
	Matrix operator *(Matrix t)
	{
		Matrix ans(r,t.c);
		ans.init();
		for(int i=0;i<r;i++)
			for(int k=0;k<c;k++) if(num[i][k])
				for(int j=0;j<t.c;j++)
					(ans[i][j]+=num[i][k]*t[k][j])%=mod;
		return ans;
	}
	Matrix operator ^(ll b)
	{
		Matrix ans(r,r),a=*this;
		ans.init(1);
		while(b)
		{
			if(b&1) ans=ans*a;
			a=a*a,b>>=1;
		}
		return ans;
	}
}base,v;
int main()
{
	int n,m;
	while(~scanf("%d%d",&n,&m))
	{
		base.r=n+2,base.c=n+2,v.r=n+2,v.c=1;
		base.init(),v.init();
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&v[i][0]);
			for(int j=1;j<=i;j++)
				base[i][j]=1;
		}
		for(int i=0;i<=n;i++)
			base[i][0]=10,base[i][n+1]=3;
		v[0][0]=23,v[n+1][0]=1;
		base[n+1][n+1]=1;
		v=(base^m)*v;
		printf("%lld\n",v[n][0]);
	}
}