#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
const int maxn=105;
struct Matrix
{
	int r,c;
	ll num[maxn][maxn];
	Matrix(int r=0,int c=0):r(r),c(c){}
	void init(ll val=0)
	{
		for(int i=0;i<r;i++)
			for(int j=0;j<c;j++)
				num[i][j]=(i==j?val:0);
	}
	Matrix operator *(const Matrix& t)
	{
		Matrix ans(r,t.c);
		ans.init();
		for(int i=0;i<r;i++)
			for(int k=0;k<c;k++) if(num[i][k])
				for(int j=0;j<t.c;j++)
					ans.num[i][j]+=num[i][k]*t.num[k][j];
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
}base,v;
int main()
{
	int n,m,k,x1,x2;
	while(~scanf("%d%d%d",&n,&m,&k)&&n)
	{
		base.r=base.c=v.r=n+1,v.c=1;
		base.init(1),v.init(),v.num[n][0]=1;
		for(int i=1;i<=k;i++)
		{
			char s[3];
			scanf("%s%d",s,&x1),x1--;
			if(s[0]=='g') base.num[x1][n]++;
			if(s[0]=='e') 
				memset(base.num[x1],0,sizeof(base.num[x1]));
			if(s[0]=='s')
			{
				scanf("%d",&x2),x2--;
				for(int j=0;j<=n;j++)
					swap(base.num[x1][j],base.num[x2][j]);
			}
		}
		v=(base^m)*v;
		for(int i=0;i<n;i++)
			printf("%lld%c",v.num[i][0],i==n-1?'\n':' ');
	}
}