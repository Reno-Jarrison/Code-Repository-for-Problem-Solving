#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2e5+5;
ll a[maxn],idx[maxn],s[maxn];
struct node
{	int l,r; }p[maxn];
bool operator <(const node& a,const node& b)
{	return idx[a.l]+idx[a.r]<idx[b.l]+idx[b.r]; }
struct Segtree
{
	ll sum[maxn<<2],cnt[maxn<<2];
	void update(int rt,int l,int r,int pos,ll val)
	{
		sum[rt]+=val,cnt[rt]++;
		if(l==r) return;
		int mid=(l+r)>>1,lson=rt<<1,rson=lson|1;
		if(pos<=mid) update(lson,l,mid,pos,val);
		else update(rson,mid+1,r,pos,val);
	}
	ll query(int rt,int l,int r,int val)
	{
		if(l==r) return idx[l]*val;
		int mid=(l+r)>>1,lson=rt<<1,rson=lson|1;
		if(val<=cnt[lson]) return query(lson,l,mid,val);
		else return sum[lson]+query(rson,mid+1,r,val-cnt[lson]);
	}
}t1,t2;
int main()
{
	int n,k,cnt=0;
	char s1[3],s2[3];
	scanf("%d%d",&k,&n);
	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		ll l,r;
		scanf("%s%lld%s%lld",s1,&l,s2,&r);
		if(s1[0]==s2[0]) 
		{	ans+=abs(l-r); continue; }
		ans++;
		a[++cnt]=l,idx[cnt]=l;
		a[++cnt]=r,idx[cnt]=r;
	}
	sort(idx+1,idx+cnt+1);
	if(k==1) 
	{
		ll mid=idx[cnt/2];
		for(int i=1;i<=cnt;i++)
			ans+=abs(idx[i]-mid);
	}
	else if(cnt)
	{
		int tot=unique(idx+1,idx+cnt+1)-idx-1;
		for(int i=1,j=1;i<=cnt;i+=2,j++)
		{
			p[j].l=lower_bound(idx+1,idx+tot+1,a[i])-idx;
			p[j].r=lower_bound(idx+1,idx+tot+1,a[i+1])-idx;
		}
		cnt>>=1,sort(p+1,p+cnt+1);
		for(int i=1;i<cnt;i++)
		{
			t1.update(1,1,tot,p[i].l,idx[p[i].l]);
			t1.update(1,1,tot,p[i].r,idx[p[i].r]);
			s[i]=t1.sum[1]-t1.query(1,1,tot,i)*2;
		}
		ll tmp=1e16;
		for(int i=cnt;i>1;i--)
		{
			t2.update(1,1,tot,p[i].l,idx[p[i].l]);
			t2.update(1,1,tot,p[i].r,idx[p[i].r]);
			tmp=min(tmp,s[i-1]+t2.sum[1]-t2.query(1,1,tot,cnt-i+1)*2);
		}
		ans+=tmp;
	}
	printf("%lld",ans);
}