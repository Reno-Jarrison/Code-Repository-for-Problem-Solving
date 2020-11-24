#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=10;
int n,mod=1e9;
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
}base(3,3),v(3,1);
int main()
{
	base[0][0]=base[1][1]=4,base[0][2]=2;
	base[1][2]=base[2][2]=1;
	v[1][0]=v[2][0]=1;
	while(~scanf("%d%d",&n,&mod))
	{
		Matrix ans=(base^(n/2))*v;
		printf("%lld\n",ans[n&1][0]);
	}
}