#include<cstdio>
#include<algorithm>
using namespace std;
int gcd(int a,int b)
{	return !b?a:gcd(b,a%b); }
int main()
{
	int t,x,y,ks=0;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&x,&y);
		int ans=0;
		while(true)
		{
			if(x<y) swap(x,y);
			ans++;
			int d=gcd(x,y),n,m;
			m=y/d;
			if((x/d)%(m+1)) break;
			n=x/d/(m+1),x=n*d;
		}
		printf("Case #%d: %d\n",++ks,ans);
	}
}