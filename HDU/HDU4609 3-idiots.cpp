#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
const int maxn=1e5+5;
const double pi=acos(-1);
struct complex
{
	double real,imag;
	complex(double a=0,double b=0):real(a),imag(b){}
	friend complex operator +(complex x,complex y)
	{	return complex(x.real+y.real,x.imag+y.imag); }
	friend complex operator -(complex x,complex y)
	{	return complex(x.real-y.real,x.imag-y.imag); }
	friend complex operator *(complex x,complex y)
	{	return complex(x.real*y.real-x.imag*y.imag,x.real*y.imag+x.imag*y.real); }
}f[maxn<<2];
int rev[maxn<<2],cnt[maxn<<2],a[maxn];
ll tmp[maxn<<2],pre[maxn<<2];
void FFT(complex *f,int n,int flag)
{
	for(int i=0;i<n;i++)
		if(i<rev[i]) swap(f[i],f[rev[i]]);
	for(int i=2;i<=n;i<<=1)
	{
		int len=i>>1;
		complex base(cos(pi/len),sin(pi/len)*flag);
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
ll C2(ll x)
{	return x*(x-1)/2; }
int main()
{
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		memset(cnt,0,sizeof(cnt));
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]),cnt[a[i]]++;
		sort(a+1,a+n+1);
		int m=1,lim=a[n]*2;
		while(m<=lim) m<<=1;
		for(int i=0;i<m;i++)
			rev[i]=(rev[i>>1]>>1)|(i&1?m>>1:0);
		for(int i=0;i<m;i++)
			f[i].real=f[i].imag=cnt[i];
		FFT(f,m,1);
		for(int i=0;i<m;i++)
			f[i]=f[i]*f[i];
		FFT(f,m,-1);
		for(int i=1;i<=lim;i++)
			tmp[i]=(ll)(f[i].imag/m/2+0.5);
		for(int i=1;i<=n;i++)
			tmp[a[i]+a[i]]--;
		for(int i=1;i<=lim;i++)
			pre[i]=pre[i-1]+tmp[i]/2;
		ll ans=0;
		for(int i=1;i<=n;i++)
		{
			ans+=pre[lim]-pre[a[i]];
			ans-=1ll*(n-i)*(i-1)+C2(n-i)+n-1;
		}
		ll tot=1ll*n*(n-1)*(n-2)/6;
		printf("%.7lf\n",1.0*ans/tot);
	}
}