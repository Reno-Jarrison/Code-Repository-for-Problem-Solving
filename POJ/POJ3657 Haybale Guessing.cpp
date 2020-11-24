#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e6+5,maxm=3e4+5;
struct node
{	int l,r,x; }p[maxn];
bool operator <(const node& a,const node& b)
{	return a.x>b.x; }
int l[maxm],r[maxm],x[maxm],f[maxn];
int find(int x)
{	return f[x]==x?f[x]:f[x]=find(f[x]); }
bool check(int m,int n)
{
	for(int i=1;i<=n+1;i++) f[i]=i;
	for(int i=1;i<=m;i++)
		p[i].l=l[i],p[i].r=r[i],p[i].x=x[i];
	sort(p+1,p+m+1);
	int lasx=-1,minl=n+1,minr=n+1,maxl=0,maxr=0;
	for(int i=1;i<=m;i++)
	{
		if(p[i].x==lasx)
		{
			minl=min(minl,p[i].l),maxl=max(maxl,p[i].l);
			minr=min(minr,p[i].r),maxr=max(maxr,p[i].r);
			if(maxl>minr) return false;
		}
		else
		{
			if(i>1&&find(maxl)>minr) return false;
			for(int pt=find(minl);pt<=maxr;pt=find(pt))
				f[pt]=find(pt+1);
			minl=maxl=p[i].l;
			minr=maxr=p[i].r;
			lasx=p[i].x;
		}
	}
	return find(maxl)<=minr;
}
int main()
{
	int n,q;
	scanf("%d%d",&n,&q);
	for(int i=1;i<=q;i++)
		scanf("%d%d%d",&l[i],&r[i],&x[i]);
	int l=1,r=q;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(check(mid,n)) l=mid+1;
		else r=mid-1;
	}
	int ans=(r==q?0:r+1);
	printf("%d\n",ans);
}