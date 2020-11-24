#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=15,mod=9973;
struct matrix
{
	int r,c;
	ll num[maxn][maxn];
	matrix(int r=0,int c=0):r(r),c(c)
	{ 	memset(num,0,sizeof(num)); }
	void init()
	{	if(r==c) for(int i=0;i<r;i++) num[i][i]=1; }
	friend matrix operator *(const matrix& a,const matrix& b)
	{
		matrix ans(a.r,b.c);
		for(int i=0;i<a.r;i++)
           for(int k=0;k<a.c;k++) if(a.num[i][k]) 
               	for(int j=0;j<b.c;j++)
					(ans.num[i][j]+=a.num[i][k]*b.num[k][j])%=mod;
		return ans;
	}
	friend matrix operator ^(matrix a,ll b)
	{
		matrix ans(a.r,a.r);
		ans.init();
		while(b)
		{
			if(b&1) ans=ans*a;
			a=a*a,b>>=1;
		}
		return ans;
	}
};
int main()
{
	int t,n,k;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		matrix a(n,n);
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				scanf("%lld",&a.num[i][j]);
		a=a^k;
		ll tr=0;
		for(int i=0;i<n;i++)
			tr=(tr+a.num[i][i])%mod;
		printf("%lld\n",tr);
	}
}