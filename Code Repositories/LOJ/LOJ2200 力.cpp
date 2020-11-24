#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const double PI=acos(-1.0);
const int maxn=1e5+5;
struct complex
{
	double real,imag;
	complex(double a=0,double b=0):real(a),imag(b){}
	friend complex operator +(const complex& x,const complex& y)
	{	return complex(x.real+y.real,x.imag+y.imag); }
	friend complex operator -(const complex& x,const complex& y)
	{	return complex(x.real-y.real,x.imag-y.imag); }
	friend complex operator *(const complex& x,const complex& y)
	{	return complex(x.real*y.real-x.imag*y.imag,x.real*y.imag+x.imag*y.real); }
}f1[maxn<<2],f2[maxn<<2],g[maxn<<2],a[maxn<<2],b[maxn<<2];
int rev[maxn<<2];
void FFT(complex *f,int n,int flag)
{
	for(int i=0;i<n;i++)
		if(i<rev[i]) swap(f[i],f[rev[i]]);
	for(int i=2;i<=n;i<<=1)
	{
		int len=i>>1;
		complex base(cos(PI/len),sin(PI/len)*flag);
		for(int j=0;j<n;j+=i)
		{
			complex w(1,0);
			for(int k=j;k<j+len;k++,w=w*base)
			{
				complex tmp=w*f[k+len];
				f[k+len]=f[k]-tmp,f[k]=f[k]+tmp;
			}
		}
	}
}
int main()
{
	int n,m;
	scanf("%d",&m);
	for(n=1;n<=m*2;n<<=1);
	for(int i=0;i<n;i++)
		rev[i]=(rev[i>>1]>>1)|(i&1?n>>1:0);
	for(int i=1;i<=m;i++)
	{
		scanf("%lf",&f1[i].real);
		f2[n-i].real=f1[i].real;
		g[i].real=(double)(1.0/i/i);
	}
	FFT(f1,n,1),FFT(f2,n,1),FFT(g,n,1);
	for(int i=0;i<n;i++)
		a[i]=f1[i]*g[i],b[i]=f2[i]*g[i];
	FFT(a,n,-1),FFT(b,n,-1);
	for(int i=1;i<=m;i++)
		printf("%.3lf\n",(a[i].real-b[n-i].real)/n);
}