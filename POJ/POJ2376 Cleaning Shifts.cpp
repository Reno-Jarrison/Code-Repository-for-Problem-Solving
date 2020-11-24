#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=3e4+5;
struct node
{	int l,r; }p[maxn];
bool operator <(const node& x,const node& y)
{	return x.l<y.l||(x.l==y.l&&x.r<y.r); }
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&p[i].l,&p[i].r);
	}
	sort(p+1,p+n+1);
	int ans=1,pt=1,mxr=1;
 	for(int i=1;i<=n;i++)
	{
		int l=p[i].l,r=p[i].r;
		if(i==1&&l>1) break;
		if(l<=pt) mxr=max(mxr,r);
		else
		{
			ans++,pt=mxr+1;
			if(l<=pt) mxr=max(mxr,r);
			else break;
		}
		if(mxr>=m) break;
 	}
	if(mxr<m) ans=-1;
	printf("%d\n",ans);
}