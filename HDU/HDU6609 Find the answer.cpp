#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
const int maxn=2e5+5;
struct tree
{	int l,r,num; ll val; }t[maxn<<2];
int w[maxn],dct[maxn];
void build(int rt,int l,int r)
{
	t[rt].l=l,t[rt].r=r,t[rt].num=t[rt].val=0;
	if(l==r) return;
	int lson=rt<<1,rson=lson|1,m=(l+r)>>1; 
	build(lson,l,m),build(rson,m+1,r);
}
int query(int rt,ll val)
{
	if(t[rt].val<=val) return t[rt].num;
	if(t[rt].l==t[rt].r)  
		return min(t[rt].num,(int)(val/dct[t[rt].l])); 
	int lson=rt<<1,rson=lson|1;
	if(t[lson].val>=val) return query(lson,val);
	return t[lson].num+query(rson,val-t[lson].val);
}
void update(int rt,int id)
{
	if(t[rt].l==t[rt].r)
	{	
		t[rt].val+=dct[id],t[rt].num++; 
		return; 
	}
	int lson=rt<<1,rson=lson|1;
	if(id<=t[lson].r) update(lson,id);
	else update(rson,id);
	t[rt].val=t[lson].val+t[rson].val;
	t[rt].num=t[lson].num+t[rson].num;
}
int main()
{
	int q,n,m,uni;
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
			scanf("%d",&w[i]),dct[i]=w[i];
		sort(dct+1,dct+n+1);
		uni=unique(dct+1,dct+n+1)-dct-1;
		build(1,1,uni);
		for(int i=1;i<=n;i++)
		{
			printf("%d ",i==1?0:i-1-query(1,m-w[i]));
			update(1,lower_bound(dct+1,dct+uni+1,w[i])-dct);
		}
		printf("\n");
	} 
}
