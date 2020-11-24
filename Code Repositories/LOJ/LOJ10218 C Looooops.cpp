#include<bits/stdc++.h>
#define ll long long
using namespace std;
void exgcd(ll a,ll b,ll& d,ll& x,ll& y)
{
	if(!b) d=a,x=1,y=0;
	else exgcd(b,a%b,d,y,x),y-=a/b*x;
}
int main()
{
	ll a,b,c,e,k,d,x,y,ans,mod;
	while(cin>>a>>b>>c>>k&&(a||b||c||k))
	{
		k=1LL<<k,ans=-1,e=b-a;
		exgcd(c,k,d,x,y);
		mod=abs(k/d);
		if(e%d==0) ans=(x*e/d%mod+mod)%mod;
		ans==-1?cout<<"FOREVER":cout<<ans;
		cout<<endl;		
	}
}