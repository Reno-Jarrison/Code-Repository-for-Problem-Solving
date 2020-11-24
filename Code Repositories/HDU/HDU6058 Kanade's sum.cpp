#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
const int maxn=5e5+5;
int a[maxn],idx[maxn],pre[maxn],suc[maxn];
ll span1[85],span2[85];
ll count(int x,int k,int n)
{
	int prept=0,sucpt=0,pt1=x,pt2=x;
	while(pt1>=1&&prept<=k)
		span1[++prept]=pt1-pre[pt1],pt1=pre[pt1];
	while(pt2<=n&&sucpt<=k)
		span2[++sucpt]=suc[pt2]-pt2,pt2=suc[pt2];
	ll ans=0;
	for(int i=max(1,k+1-sucpt);i<=min(prept,k);i++)
		ans+=span1[i]*span2[k+1-i];
	return ans;
}
void del(int x)
{	suc[pre[x]]=suc[x],pre[suc[x]]=pre[x]; }
int main()
{
	int t,n,k;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]),idx[a[i]]=i;
			pre[i]=i-1,suc[i]=i+1;
		}
		ll ans=0;
		for(int i=1;i<=n;i++)
			ans+=count(idx[i],k,n)*i,del(idx[i]);
		printf("%lld\n",ans);
	}
}	