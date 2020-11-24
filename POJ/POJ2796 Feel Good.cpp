#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
const int maxn=1e5+5;
int a[maxn],stk[maxn],l[maxn],r[maxn];
ll s[maxn];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		s[i]=s[i-1]+a[i],l[i]=1,r[i]=n;
	}
	for(int i=1,top=0;i<=n;i++)
	{
		while(top&&a[stk[top]]>a[i])
			r[stk[top--]]=i-1;
		stk[++top]=i;
	}
	for(int i=n,top=0;i;i--)
	{
		while(top&&a[stk[top]]>a[i])
			l[stk[top--]]=i+1;
		stk[++top]=i;
	}
	ll ans=-1;
	int lid=1,rid=n;
	for(int i=1;i<=n;i++)
	{
		ll cur=(s[r[i]]-s[l[i]-1])*a[i];
		if(cur>ans) ans=cur,lid=l[i],rid=r[i];
	}
	printf("%lld\n%d %d\n",ans,lid,rid);
}