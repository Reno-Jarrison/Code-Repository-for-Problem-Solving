#include<cstdio>
#define ll long long
using namespace std;
ll gcd(ll x,ll y)
{	return y?gcd(y,x%y):x; }
struct fraction
{
	ll numer,denom; bool neg;
	fraction(){}
	fraction(ll n,ll d,bool neg):numer(n),denom(d),neg(neg){}
	void update()
	{
		ll d=gcd(numer,denom);
		if(numer<0) neg^=1,numer=-numer;
		if(denom<0) neg^=1,denom=-denom;
		numer/=d,denom/=d;
	}
	friend fraction operator *(const fraction &x,const fraction &y)
	{
		fraction tmp(x.numer*y.numer,x.denom*y.denom,x.neg^y.neg);
		tmp.update();
		return tmp;
	}
	friend fraction operator *(const fraction &x,const int &y)
	{
		fraction tmp(x.numer*y,x.denom,x.neg);
		tmp.update();
		return tmp;
	}
	friend fraction operator +(const fraction &x,const fraction &y)
	{
		fraction tmp(0,x.denom*y.denom,false);
		tmp.numer+=x.numer*y.denom*(x.neg?-1:1);
		tmp.numer+=y.numer*x.denom*(y.neg?-1:1);
		tmp.update();
		return tmp;
	}
}ans[35];
int main()
{
	ans[1].numer=ans[1].denom=1;
	for(int i=2;i<=33;i++)
	{
		fraction tmp(1,i,false);
		ans[i]=ans[i-1]+tmp;
	}
	int n;
	while(~scanf("%d",&n))
	{
		fraction tmp=ans[n]*n;
		ll x=tmp.numer/tmp.denom;
		ll y=tmp.numer%tmp.denom;
		ll z=tmp.denom;
		if(!y) printf("%lld\n",x);
		else 
		{
			int len1=0,len2=0;
			ll tnum=x;
			while(tnum) len1++,tnum/=10;
			tnum=z;
			while(tnum) len2++,tnum/=10;
			for(int i=0;i<=len1;i++) putchar(' ');
			printf("%lld\n%lld%c",y,x,' ');
			for(int i=1;i<=len2;i++) putchar('-');
			puts("");
			for(int i=0;i<=len1;i++) putchar(' ');
			printf("%lld\n",z);
		}
	}
}
