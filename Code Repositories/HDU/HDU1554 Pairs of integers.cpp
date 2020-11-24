#include<cstdio>
#include<set>
#define ll long long
using namespace std;
ll pow10[10]={1},n;
ll gcd(ll a,ll b)
{	return !b?a:gcd(b,a%b); }
void exgcd(ll a,ll b,ll &x,ll &y,ll &d)
{
	if(!b) d=a,x=1,y=0;
	else exgcd(b,a%b,y,x,d),y-=a/b*x;
}
int main()
{
	for(int i=1;i<10;i++) pow10[i]=pow10[i-1]*10;
	while(~scanf("%lld",&n))
	{
		set<int>ans;
		for(int i=0;i<10;i++)
			for(int j=0;j<10;j++)
			{
				ll c=n-i*pow10[j],a=2,b=11*pow10[j],l,h,d=gcd(a,b);
				if(c<0||c%d) continue;
				a/=d,b/=d,c/=d;
				exgcd(a,b,l,h,d);
				l=(l*c%b+b)%b,h=(c-l*a)/b;
				while(l<pow10[j]&&h>=0)
				{
					ll x=l+i*pow10[j]+h*pow10[j+1],y=l+h*pow10[j];
					if(x+y==n&&x!=y) ans.insert(x);
					l+=b,h-=a;
				}
			}
		printf("%d\n",ans.size());
		for(int x:ans) 
		{
			int tmp=x,cnt=0;
			while(tmp) cnt++,tmp/=10;
			printf("%d + %0*lld = %lld\n",x,cnt-1,n-x,n);
		}
	}
}