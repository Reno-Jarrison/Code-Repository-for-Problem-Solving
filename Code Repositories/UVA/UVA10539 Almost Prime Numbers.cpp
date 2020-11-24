#include<cstdio>
#define ll long long
using namespace std;
const int maxn=1e6+5;
int pcnt,p[maxn],vis[maxn],n;
void getprime()
{
	for(int i=2;i<maxn;i++)
	{
		if(!vis[i]) p[++pcnt]=i;
		for(int j=1;i*p[j]<maxn;j++)
		{
			vis[i*p[j]]=1;
			if(i%p[j]==0) break;
		}
	}
}
int cal(ll x)
{
	if(x<=1) return 0;
	int ans=0;
	for(int i=1;i<=pcnt&&p[i]<=x;i++)
	{
		ll tmp=1LL*p[i]*p[i];
		while(tmp<=x) ans++,tmp*=p[i];
	}
	return ans;
}
int main()
{
	getprime();
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		ll l,h;
		scanf("%lld%lld",&l,&h);
		printf("%d\n",cal(h)-cal(l-1));
	}
}