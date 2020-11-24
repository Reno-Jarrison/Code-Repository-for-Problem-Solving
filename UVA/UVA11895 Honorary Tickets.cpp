#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll gcd(ll a,ll b)
{	return !b?a:gcd(b,a%b); }
struct fraction
{
	ll numer,denom;
	fraction(ll n=1,ll d=1):numer(n),denom(d){}
	void update()
	{
		ll d=gcd(numer,denom);
		numer/=d,denom/=d;
	}
	friend bool operator <(const fraction& x,const fraction& y)
	{	return x.numer*y.denom<y.numer*x.denom; }
	friend fraction operator /(const fraction &x,const fraction &y)
	{
		fraction tmp(x.numer*y.denom,x.denom*y.numer);
		tmp.update();
		return tmp;
	}
	friend fraction operator -(const fraction &x,const fraction &y)
	{
		fraction tmp(0,x.denom*y.denom);
		tmp.numer=x.numer*y.denom-y.numer*x.denom;
		tmp.update();
		return tmp;
	}
};
struct node
{	
	fraction exp,tot;
	node(){}
	node(fraction exp,fraction tot):exp(exp),tot(tot){}
};
bool operator <(const node& x,const node& y)
{	return x.exp/x.tot<y.exp/y.tot; }
int main()
{
	int t,n,k,a,b;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		priority_queue<node>hp;
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d",&a,&b);
			hp.push(node(fraction(b,1),fraction(a,1)));
		}
		for(int i=1;i<k;i++)
		{
			node tmp=hp.top(),cur; hp.pop();
			fraction exp=tmp.exp,tot=tmp.tot;
			cur.exp=exp-exp/tot,cur.tot=tot;
			hp.push(cur);
		}
		node tmp=hp.top();
		fraction ans=tmp.exp/tmp.tot;
		printf("%lld/%lld\n",ans.numer,ans.denom);
	}
}