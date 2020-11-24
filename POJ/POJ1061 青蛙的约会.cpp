#include<iostream>
#define ll long long
using namespace std;
void exgcd(ll a,ll b,ll& d,ll& x,ll& y)
{
	if(!b) d=a,x=1,y=0;
	else exgcd(b,a%b,d,y,x),y-=a/b*x;
 } 
int main()
{
	ll x,y,m,n,l;
	cin>>x>>y>>m>>n>>l;
	ll a=m-n,b=l,c=y-x,d,x0,y0,mod;
	exgcd(a,b,d,x0,y0);
	if(c%d) cout<<"Impossible";
	else
	{
		mod=b/d,mod<0?mod=-mod:false;
		x0=(x0*c/d%mod+mod)%mod;
		cout<<x0; 
	}
}
