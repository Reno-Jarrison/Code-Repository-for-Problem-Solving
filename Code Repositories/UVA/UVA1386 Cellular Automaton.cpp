#include<cstdio>
#include<cstring>
using namespace std;
int mod;
struct cmatrix
{
	int n;
	int num[505];
	cmatrix(int n):n(n)
	{	memset(num,0,sizeof(num)); }
	friend cmatrix operator *(const cmatrix& x,const cmatrix& y)
	{
		cmatrix ans(x.n);
		for(int i=0;i<ans.n;i++) if(x.num[i])
			for(int j=0;j<ans.n;j++)
				(ans.num[(j-i+ans.n)%ans.n]+=1LL*x.num[i]*y.num[j]%mod)%=mod;
		return ans;
	}
	friend cmatrix cmqpow(cmatrix a,int b)
	{
		cmatrix ans(a.n);
		ans.num[0]=1;
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
	int n,d,k;
	while(~scanf("%d%d%d%d",&n,&mod,&d,&k))
	{
		cmatrix base(n),f(n);
		base.num[0]=1;
		for(int i=1;i<=d;i++)
			base.num[i]=base.num[n-i]=1;
		for(int i=0;i<n;i++)
			scanf("%d",&f.num[i]);
		f=cmqpow(base,k)*f;
		for(int i=0;i<n;i++)
			printf("%d%c",f.num[i],(i==n-1)?'\n':' ');
	}
}