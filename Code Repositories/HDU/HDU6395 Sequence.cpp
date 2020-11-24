#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod=1e9+7;
struct matrix
{
	int r,c;
	ll num[4][4];
	matrix(int r=0,int c=0):r(r),c(c)
	{	memset(num,0,sizeof(num)); }
	void init()
	{	for(int i=0;i<r;i++) num[i][i]=1; }
	friend matrix operator *(const matrix& a,const matrix& b)
	{
		matrix ans(a.r,b.c);
		for(int i=0;i<a.r;i++)
			for(int k=0;k<a.c;k++) if(a.num[i][k])
				for(int j=0;j<b.c;j++)
					ans.num[i][j]=(ans.num[i][j]+a.num[i][k]*b.num[k][j])%mod;
		return ans;
	}
	friend matrix mqpow(matrix a,ll b)
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
	int t;
	scanf("%d",&t);
	ll a,b,c,d,p,n;
	while(t--)
	{
		scanf("%lld%lld%lld%lld%lld%lld",&a,&b,&c,&d,&p,&n);
		if(n==1) printf("%lld\n",a);
		else if(n==2) printf("%lld\n",b);
		else
		{
			matrix base(3,3),f(3,1);
			base.num[0][0]=d,base.num[0][1]=c;
			base.num[0][2]=base.num[1][0]=base.num[2][2]=1;
			f.num[0][0]=b,f.num[1][0]=a;
			for(ll l=3,r;l<=n;l=r+1)
			{
				if(p/l) r=min(p/(p/l),n);
				else r=n;
				f.num[2][0]=p/l;
				f=mqpow(base,r-l+1)*f;
			}
			printf("%lld\n",f.num[0][0]);
		}
	}
}