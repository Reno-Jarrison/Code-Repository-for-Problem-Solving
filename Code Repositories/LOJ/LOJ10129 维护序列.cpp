#include<bits/stdc++.h>
#define ll long long
#define maxn 100005
#define init mid=(t[rt].l+t[rt].r)>>1,lson=rt<<1,rson=lson|1
#define ADD(x,y) (((x)+(y))%mod)
#define MUL(x,y) (((x)*(y))%mod)
using namespace std;
ll mod,a[maxn];
struct tree { ll l,r,sum,add,mul; }t[maxn<<2];
inline void push_tag(int rt,ll add,ll mul)
{
	t[rt].sum=MUL(t[rt].sum,mul);
	t[rt].sum=ADD(t[rt].sum,MUL((t[rt].r-t[rt].l+1),add));
	t[rt].add=MUL(t[rt].add,mul);
	t[rt].add=ADD(t[rt].add,add);
	t[rt].mul=MUL(t[rt].mul,mul);
}
inline void push_down(int rt)
{
	ll add=t[rt].add,mul=t[rt].mul;
	push_tag(rt<<1,add,mul);
	push_tag(rt<<1|1,add,mul);
	t[rt].add=0,t[rt].mul=1;
}
inline void push_up(int rt)
{ t[rt].sum=ADD(t[rt<<1].sum,t[rt<<1|1].sum); }
void build(int rt,int l,int r)
{
	t[rt].l=l,t[rt].r=r;
	t[rt].add=0,t[rt].mul=1;
	if(l==r) { t[rt].sum=a[l]; return; }
	int init;
	build(lson,l,mid),build(rson,mid+1,r);
	push_up(rt);
}
void update(int rt,ll l,ll r,ll val,int o)
{
	if(t[rt].l==l&&t[rt].r==r)
	{
		if(o==2)
		{
			t[rt].sum=ADD(t[rt].sum,MUL((r-l+1),val));
			t[rt].add=ADD(t[rt].add,val);
		}
		else
		{
			t[rt].sum=MUL(t[rt].sum,val);
			t[rt].mul=MUL(t[rt].mul,val);
			t[rt].add=MUL(t[rt].add,val);
		}
		return;
	}
	int init;
	push_down(rt);
	if(r<=mid) update(lson,l,r,val,o);
	else if(l>mid) update(rson,l,r,val,o);
	else update(lson,l,mid,val,o),update(rson,mid+1,r,val,o);
	push_up(rt);	
}
ll query(int rt,ll l,ll r)
{
	if(t[rt].l==l&&t[rt].r==r)
		return t[rt].sum;
	int init;
	push_down(rt);
	if(r<=mid) return query(lson,l,r);
	else if(l>mid) return query(rson,l,r);
	else return ADD(query(lson,l,mid),query(rson,mid+1,r));
}
int main()
{
	int n,m,o;
	ll l,r,c;
	scanf("%d%lld",&n,&mod);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	build(1,1,n);
	scanf("%d",&m);
	while(m--)
	{
		scanf("%d%lld%lld",&o,&l,&r);
		if(o==3) printf("%lld\n",query(1,l,r));
		else scanf("%lld",&c),update(1,l,r,c,o);
	}
}