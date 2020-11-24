#include<cstdio>
#define ll long long
using namespace std;
const int maxn=1e5+5;
const ll mod=10007;
struct tree
{	ll sum1,sum2,sum3,tag1,tag2; }t[maxn<<2];
void build(int rt,int l,int r)
{
	t[rt].sum1=t[rt].sum2=t[rt].sum3=t[rt].tag1=0;
	t[rt].tag2=1;
	if(l==r) return;
	int mid=(l+r)>>1,lson=rt<<1,rson=lson|1;
	build(lson,l,mid);
	build(rson,mid+1,r);
}
void modify(int rt,ll a,ll b,ll cnt)
{
	ll a2=a*a%mod,b2=b*b%mod,a3=a2*a%mod,b3=b2*b%mod;
	ll &sum1=t[rt].sum1,&sum2=t[rt].sum2,&sum3=t[rt].sum3;
	ll &tag1=t[rt].tag1,&tag2=t[rt].tag2;
	sum3=(b3*sum3+3*a*b2*sum2+3*a2*b*sum1+a3*cnt)%mod;
	sum2=(b2*sum2+2*a*b*sum1+a2*cnt)%mod;
	sum1=(b*sum1+a*cnt)%mod;
	tag1=(b*tag1+a)%mod,tag2=(b*tag2)%mod;
}
void push_down(int rt,int l,int r)
{
	int mid=(l+r)>>1,lson=rt<<1,rson=lson|1;
	modify(lson,t[rt].tag1,t[rt].tag2,mid-l+1);
	modify(rson,t[rt].tag1,t[rt].tag2,r-mid);
	t[rt].tag1=0,t[rt].tag2=1;
}
void push_up(int rt)
{
	int lson=rt<<1,rson=lson|1;
	t[rt].sum1=(t[lson].sum1+t[rson].sum1)%mod;
	t[rt].sum2=(t[lson].sum2+t[rson].sum2)%mod;
	t[rt].sum3=(t[lson].sum3+t[rson].sum3)%mod;
}
void update(int rt,int L,int R,int l,int r,int val,int o)
{
	if(L<=l&&r<=R)
	{
		ll cnt=r-l+1,val2=val*val%mod,val3=val2*val%mod;
		if(o==1)
		{
			t[rt].sum3=(t[rt].sum3+3*val*t[rt].sum2+3*val2*t[rt].sum1+val3*cnt)%mod;
			t[rt].sum2=(t[rt].sum2+2*val*t[rt].sum1+val2*cnt)%mod;
			t[rt].sum1=(t[rt].sum1+val*cnt)%mod;
			t[rt].tag1=(t[rt].tag1+val)%mod;
		}
		if(o==2)
		{
			t[rt].sum1=(val*t[rt].sum1)%mod;
			t[rt].sum2=(val2*t[rt].sum2)%mod;
			t[rt].sum3=(val3*t[rt].sum3)%mod;
			t[rt].tag1=(val*t[rt].tag1)%mod;
			t[rt].tag2=(val*t[rt].tag2)%mod;
		}
		return;
	}
	int mid=(l+r)>>1,lson=rt<<1,rson=lson|1;
	push_down(rt,l,r);
	if(L<=mid) update(lson,L,R,l,mid,val,o);
	if(R>mid) update(rson,L,R,mid+1,r,val,o);
	push_up(rt);
}
int query(int rt,int L,int R,int l,int r,int p)
{
	if(L<=l&&r<=R)
	{
		if(p==1) return t[rt].sum1;
		if(p==2) return t[rt].sum2;
		if(p==3) return t[rt].sum3;
	}
	push_down(rt,l,r);
	int mid=(l+r)>>1,lson=rt<<1,rson=lson|1,ans=0;
	if(L<=mid) ans+=query(lson,L,R,l,mid,p);
	if(R>mid) ans+=query(rson,L,R,mid+1,r,p);
	return ans%mod;
}
int main()
{
	int n,m,o,l,r,x;
	while(scanf("%d%d",&n,&m)&&n)
	{
		build(1,1,n);
		for(int i=1;i<=m;i++)
		{
			scanf("%d%d%d%d",&o,&l,&r,&x);
			if(o==4) printf("%d\n",query(1,l,r,1,n,x));
			else if(o==3) update(1,l,r,1,n,0,2),update(1,l,r,1,n,x,1);
			else update(1,l,r,1,n,x,o);
		}
	}
}