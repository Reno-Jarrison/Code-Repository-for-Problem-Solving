#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e6;
int cnt,root[maxn+5];
struct node
{	int l,r; ll num,sum; }t[maxn<<5];
void update(int& rt,int prt,int l,int r,ll val)
{
	rt=++cnt,t[rt]=t[prt];
	t[rt].num++,t[rt].sum+=val; 
	if(l==r) return;
	int mid=(l+r)>>1;
	if(val<=mid) update(t[rt].l,t[prt].l,l,mid,val);
	else update(t[rt].r,t[prt].r,mid+1,r,val);
}
ll query(int L,int R,int l,int r,ll k,ll tnum)
{
	ll num=t[R].num-t[L].num,sum=t[R].sum-t[L].sum;
	if(num==0) return 0;
	if(k+tnum<=l) return sum-(((k<<1)+(tnum<<1)+num-1)*num>>1);
	if(r<=k+tnum+num-1) return (((k<<1)+(tnum<<1)+num-1)*num>>1)-sum;
	int mid=(l+r)>>1,lnum=t[t[R].l].num-t[t[L].l].num;
	return query(t[L].l,t[R].l,l,mid,k,tnum)+query(t[L].r,t[R].r,mid+1,r,k,tnum+lnum);
}
int main()
{
	int n,m,l,r;
	ll a,k;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a),update(root[i],root[i-1],1,maxn,a);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%lld",&l,&r,&k);
		printf("%lld\n",query(root[l-1],root[r],1,maxn,k,0));
	}
}