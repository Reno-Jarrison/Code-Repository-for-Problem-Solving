#include<bits/stdc++.h>
#define lowbit(x) (x&(-x))
using namespace std;
const int maxn=3e5+5;
int tot,a[maxn],tree[maxn],ans[maxn];
int query(int x)
{
	int res=0;
	while(x) res+=tree[x],x-=lowbit(x);
	return res;
}
void update(int x,int val)
{	while(x<=tot) tree[x]+=val,x+=lowbit(x); }
void modify(int l,int r)
{	update(l,1),update(r+1,-1); }
struct Query
{	int id,l,r; }q[maxn];
bool operator <(const Query& x,const Query& y)
{	return x.r<y.r; }
int main()
{
	int n,m,x,u,v,pt=1;
	scanf("%d%d",&n,&m),tot=n;
	for(int i=1;i<=n;i++)
		scanf("%d",&x),a[i]=i-x;
	for(int i=1;i<=m;i++)
		scanf("%d%d",&u,&v),q[i].l=1+u,q[i].r=n-v,q[i].id=i;
	sort(q+1,q+m+1);
	for(int i=1;i<=n;i++)
	{
		int l=1,r=i;
		while(l<=r)
		{
			int mid=(l+r)>>1;
			if(query(mid)>=a[i]) l=mid+1;
			else r=mid-1;
		}
		if(a[i]>=0&&r>0) modify(1,r);
		while(q[pt].r==i)
			ans[q[pt].id]=query(q[pt].l),pt++;
	}
	for(int i=1;i<=m;i++)
		printf("%d\n",ans[i]);
}