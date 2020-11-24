#include<cstdio>
#include<cstring>
using namespace std;
int mod;
struct matrix
{
	int r,c;
	int num[20][20];
	matrix(int r,int c):r(r),c(c)
	{	memset(num,0,sizeof(num)); }
	void init()
	{
		memset(num,0,sizeof(num));
		for(int i=1;i<=r;i++) num[i][i]=1;
	}
	friend matrix operator *(const matrix& x,const matrix& y)
	{
		matrix ans(x.r,y.c);
		for(int i=1;i<=x.r;i++)
			for(int k=1;k<=x.c;k++)
				if(x.num[i][k])
					for(int j=1;j<=y.c;j++)
						(ans.num[i][j]+=x.num[i][k]*y.num[k][j]%mod)%=mod;
		return ans;
	}
	friend matrix mqpow(matrix a,int b)
	{
		matrix ans(a.r,a.c);
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
	int d,n,ans;
	while(scanf("%d%d%d",&d,&n,&mod)&&d)
	{
		matrix base(d,d),f(d,1);
		for(int i=1;i<d;i++)
			base.num[i+1][i]=1;
		for(int i=1;i<=d;i++)
			scanf("%d",&base.num[1][i]),base.num[1][i]%=mod;
		for(int i=1;i<=d;i++)
			scanf("%d",&f.num[d-i+1][1]),f.num[d-i+1][1]%=mod;
		if(n<=d) ans=f.num[d-n+1][1];
		else f=mqpow(base,n-d)*f,ans=f.num[1][1];
		printf("%d\n",ans);
	}
}