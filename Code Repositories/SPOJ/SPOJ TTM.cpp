#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e5+5;
int cnt,root[maxn];
ll num[maxn];
struct node
{	ll sum,tag; int l,r; }t[maxn<<5];
void build(int& rt,int l,int r)
{
	rt=++cnt;
	if(l==r) { t[rt].sum=num[l]; return; }
	int mid=(l+r)>>1;
	build(t[rt].l,l,mid);
	build(t[rt].r,mid+1,r);
	t[rt].sum=t[t[rt].l].sum+t[t[rt].r].sum;
}
void update(int& rt,int prt,ll L,ll R,ll l,ll r,ll val)
{
	rt=++cnt,t[rt]=t[prt];
	t[rt].sum+=val*(min(R,r)-max(L,l)+1);
	if(L<=l&&r<=R)
	{	t[rt].tag+=val;	return; }
	ll mid=(l+r)>>1;
	if(L<=mid) update(t[rt].l,t[prt].l,L,R,l,mid,val);
	if(R>mid) update(t[rt].r,t[prt].r,L,R,mid+1,r,val);
}
ll query(int rt,ll L,ll R,ll l,ll r,ll tmp)
{
	if(L<=l&&r<=R) return t[rt].sum+tmp*(r-l+1);
	ll mid=(l+r)>>1,ans=0;
	if(L<=mid) ans+=query(t[rt].l,L,R,l,mid,tmp+t[rt].tag);
	if(R>mid) ans+=query(t[rt].r,L,R,mid+1,r,tmp+t[rt].tag);
	return ans;
}
int main()
{
	int n,m,t=0;
	ll d,l,r,x;
	char o[3];
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&num[i]);
	build(root[0],1,n);
	for(int i=1;i<=m;i++)
	{
		scanf("%s",o);
		if(o[0]=='B') scanf("%d",&t);
		else if(o[0]=='C') 
		{
			scanf("%lld%lld%lld",&l,&r,&d);
			update(root[t+1],root[t],l,r,1,n,d),t++;
		}
		else 
		{
			scanf("%lld%lld",&l,&r);
			if(o[0]=='H') scanf("%lld",&x);
			else x=t;
			printf("%lld\n",query(root[x],l,r,1,n,0));
		}
	}
}
