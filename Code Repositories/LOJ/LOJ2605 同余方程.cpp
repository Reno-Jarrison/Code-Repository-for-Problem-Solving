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
	ll a,b,d,x,y;
	cin>>a>>b;
	exgcd(a,b,d,x,y);
	printf("%lld",(x+b)%b);
}