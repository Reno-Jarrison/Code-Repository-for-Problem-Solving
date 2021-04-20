#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
const double pi=acos(-1.0);
const int maxn=5e4+5;
struct complex
{
	double real,imag;
	complex(double a=0,double b=0):real(a),imag(b){}
	friend complex operator +(const complex &x,const complex &y)
	{	return complex(x.real+y.real,x.imag+y.imag); }
	friend complex operator -(const complex &x,const complex &y)
	{	return complex(x.real-y.real,x.imag-y.imag); }
	friend complex operator *(const complex &x,const complex &y)
	{	return complex(x.real*y.real-x.imag*y.imag,x.real*y.imag+x.imag*y.real); }
}a[maxn<<2];
int rev[maxn<<2],ans[maxn<<1];
char num1[maxn],num2[maxn];
void fft(complex *f,int n,int flag)
{
	for(int i=0;i<n;i++)
		if(i<rev[i]) swap(f[i],f[rev[i]]);
	for(int i=2;i<=n;i<<=1)
	{
		int len=i>>1;
		complex bas(cos(pi/len),sin(pi/len)*flag);
		for(int j=0;j<n;j+=i)
		{
			complex w(1,0);
			for(int k=j;k<j+len;k++,w=w*bas)
			{
				complex tmp=w*f[k+len];
				f[k+len]=f[k]-tmp,f[k]=f[k]+tmp;
			}
		}
	}
}
int main()
{
	while(~scanf("%s%s",num1,num2))
	{
		int n=strlen(num1)-1,m=strlen(num2)-1;
		for(int i=0;i<maxn<<2;i++)
			a[i].real=0,a[i].imag=0;
		for(int i=0;i<=n;i++)
			a[i].real=num1[n-i]-'0';
		for(int i=0;i<=m;i++)
			a[i].imag=num2[m-i]-'0';
		for(m+=n,n=1;n<=m;n<<=1);
		for(int i=0;i<n;i++)
			rev[i]=(rev[i>>1]>>1)|(i&1?n>>1:0);
		fft(a,n,1);
		for(int i=0;i<n;i++)
			a[i]=a[i]*a[i];
		fft(a,n,-1);
		memset(ans,0,sizeof(ans));
		for(int i=0;i<=m;i++)
		{
			ans[i]+=(int)(a[i].imag/n/2+0.5);
			ans[i+1]+=ans[i]/10,ans[i]%=10;
		}
		while(ans[m+1]) m++,ans[m+1]=ans[m]/10,ans[m]%=10;
		while(!ans[m]) m--;
		if(m<0) m=0;
		for(int i=m;i>=0;i--)
			printf("%d",ans[i]);
		puts("");
	}
}