#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=5;
struct matrix
{
	int r,c;
	ll num[maxn][maxn];
	matrix(int r,int c):r(r),c(c)
		{ memset(num,0,sizeof(num)); }
	void init()
	{	if(r==c) for(int i=0;i<r;i++) num[i][i]=1; }
};
ll qmul(ll a,ll b,ll p)
{
	ll ans=0;
	while(b)
	{
		if(b&1) (ans+=a)%=p;
		(a+=a)%=p,b>>=1;
	}
	return ans;
}
matrix mmul(matrix a,matrix b,ll p)
{
	matrix tmp(a.r,b.c);
	for(int i=0;i<a.r;i++)
		for(int j=0;j<b.c;j++)
			for(int k=0;k<a.c;k++)
				(tmp.num[i][j]+=qmul(a.num[i][k],b.num[k][j],p))%=p; 
	return tmp;
}
matrix mqpow(matrix a,ll b,ll p)
{
	matrix ans(3,3);
	ans.init();
	while(b)
	{
		if(b&1) ans=mmul(ans,a,p);
		a=mmul(a,a,p),b>>=1;
	}
	return ans;
}
int main()
{
	ll m,b,c,x1,n,g;
	cin>>m>>b>>c>>x1>>n>>g;
	matrix base(2,2),a(2,1);
	a.num[0][0]=x1;
	a.num[1][0]=1;
	base.num[0][0]=b%m;
	base.num[0][1]=c%m;
	base.num[1][1]=1;
	matrix ans=mmul(mqpow(base,n,m),a,m);
	cout<<ans.num[0][0]%g;
}