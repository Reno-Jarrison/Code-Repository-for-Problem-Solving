#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=10,mod=100;
struct Matrix
{
	int r,c;
	ll num[maxn][maxn];
	Matrix(int r,int c):r(r),c(c){}
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
					ans[i][j]=(ans[i][j]+num[i][k]*t[k][j])%mod;
		return ans;
	}
	Matrix operator ^(ll k)
	{
		Matrix ans(r,r),a=*this;
		ans.init(1);
		while(k)
		{
			if(k&1) ans=ans*a;
			a=a*a,k>>=1;
		}
		return ans;
	}
}base(4,4),v(4,1);
int main()
{
	base[0][0]=2,base[0][1]=1,base[0][2]=1,base[0][3]=0;
	base[1][0]=1,base[1][1]=2,base[1][2]=0,base[1][3]=1;
	base[2][0]=1,base[2][1]=0,base[2][2]=2,base[2][3]=1;
	base[3][0]=0,base[3][1]=1,base[3][2]=1,base[3][3]=2;
	int t,ks=0;
	while(scanf("%d",&t)&&t)
	{
		while(t--)
		{
			ll k;
			scanf("%lld",&k);
			v[0][0]=1,v[1][0]=v[2][0]=v[3][0]=0;
			v=(base^k)*v;
			printf("Case %d: %lld\n",++ks,v[0][0]);
		}
		puts(""),ks=0;
	}
}