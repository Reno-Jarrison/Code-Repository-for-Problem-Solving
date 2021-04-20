#include<bits/stdc++.h>
#define lowbit(x) ((x)&(-x))
using namespace std;
const int maxn=1e5+5,maxm=2e5+5;
struct node
{	int id,a,b,c; }p[maxn],buf[maxn];
bool operator <(const node& x,const node& y)
{	return x.a<y.a||(x.a==y.a&&(x.b<y.b||(x.b==y.b&&x.c<y.c))); }
bool operator ==(const node& x,const node& y)
{	return x.a==y.a&&x.b==y.b&&x.c==y.c; }
int w[maxn],tree[maxm],cnt[maxn],ans[maxn],lim;
void update(int x,int val)
{	while(x<=lim) tree[x]+=val,x+=lowbit(x); }
int query(int x)
{
	int ans=0;
	while(x)
		ans+=tree[x],x-=lowbit(x);
	return ans;
}
void cdq(int l,int r)
{
	if(l==r) return;
	int mid=(l+r)>>1,i=l,j=mid+1,k=l;
	cdq(l,mid),cdq(mid+1,r);
	while(i<=mid&&j<=r)
	{
		if(p[i].b<=p[j].b) 
			update(p[i].c,w[p[i].id]),buf[k++]=p[i++];
		else
			cnt[p[j].id]+=query(p[j].c),buf[k++]=p[j++];
	}
	while(i<=mid)
		update(p[i].c,w[p[i].id]),buf[k++]=p[i++];
	while(j<=r)
		cnt[p[j].id]+=query(p[j].c),buf[k++]=p[j++];
	for(int it=l;it<=mid;it++)
		update(p[it].c,-w[p[it].id]);
	for(int it=l;it<=r;it++)
		p[it]=buf[it];
}
int main()
{
	int n,tot=0;
	scanf("%d%d",&n,&lim);
	for(int i=1;i<=n;i++)
		scanf("%d%d%d",&p[i].a,&p[i].b,&p[i].c);
	sort(p+1,p+n+1);
	for(int i=1;i<=n;i++)
		if(p[i]==p[i-1]) w[tot]++;
		else p[++tot]=p[i],p[tot].id=tot,w[tot]=1;
	cdq(1,tot);
	for(int i=1;i<=tot;i++)
		ans[cnt[i]+w[i]-1]+=w[i];
	for(int i=0;i<n;i++)
		printf("%d\n",ans[i]);
}