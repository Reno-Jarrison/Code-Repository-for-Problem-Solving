#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
const ll mod=1e4+1;
int num[205];
void exgcd(ll a,ll b,ll &d,ll &x,ll &y)
{	
	if(b) exgcd(b,a%b,d,y,x),y-=a/b*x;
	else d=a,x=1,y=0; 
}
int f(ll a,ll b,ll x)
{	return (a*x+b)%mod; }
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<n*2;i+=2)
		scanf("%d",&num[i]);
	for(ll a=0;a<mod;a++)
	{
		ll x,y,d,m,c=num[3]-a*a*num[1];
		exgcd(a+1,mod,d,x,y);
		if(c%d) continue;
		m=abs(mod/d);
		ll b=(x*c/d%m+m)%m;
		b=x*c/d;
		bool flag=true;
		for(int i=2;i<=n*2;i++)
			if((i&1)&&f(a,b,num[i-1])!=num[i])
			{	flag=false; break; }
			else if(!(i&1)) num[i]=f(a,b,num[i-1]);
		if(flag) break;
	}
	for(int i=2;i<=n*2;i+=2)
		printf("%d\n",num[i]);

}