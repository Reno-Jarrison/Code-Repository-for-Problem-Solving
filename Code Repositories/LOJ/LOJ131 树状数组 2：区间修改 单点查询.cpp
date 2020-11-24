#include<cstdio>
#define ll long long
#include<iostream>
#define lowbit(x) ((x)&(-x))
using namespace std;
const int maxn=1e6+5;
ll tree[maxn];
void update(int x,ll val,int n)
{	while(x<=n) tree[x]+=val,x+=lowbit(x); }
ll query(int x)
{
	ll ans=0;
	while(x) ans+=tree[x],x-=lowbit(x);
	return ans;
}
void modify(int l,int r,ll val,int n)
{	update(l,val,n),update(r+1,-val,n); }
int main()
{
	int n,q,o,l,r,pos;
	ll a,x;
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a),modify(i,i,a,n);
	for(int i=1;i<=q;i++)
	{
		scanf("%d",&o);
		if(o==1) scanf("%d%d%lld",&l,&r,&x),modify(l,r,x,n);
		if(o==2) scanf("%d",&pos),printf("%lld\n",query(pos));
	}
}