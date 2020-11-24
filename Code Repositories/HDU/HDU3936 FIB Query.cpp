#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=1e9+7;
struct Matrix
{
	int r,c;
	ll num[5][5];
	Matrix(int r=0,int c=0):r(r),c(c){}
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
}base(3,3),v(3,1);
ll solve(ll x)
{
	if(x<=0) return 0;
	v[0][0]=2,v[1][0]=1,v[2][0]=2;
	v=(base^(x-1))*v;
	return v[2][0];
}
int main()
{
	base[0][0]=5,base[0][1]=3,base[0][2]=0;
	base[1][0]=3,base[1][1]=2,base[1][2]=0;
	base[2][0]=5,base[2][1]=3,base[2][2]=1;
	int T;
	scanf("%d",&T);
	while(T--)
	{
		ll l,r;
		scanf("%lld%lld",&l,&r);
		printf("%lld\n",(solve(r)-solve(l-1)+mod)%mod);
	}
}