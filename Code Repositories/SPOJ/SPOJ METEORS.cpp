#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
#define ll long long
#define lowbit(x) ((x)&(-x))
const int maxn=3e5+5;
int n,m,k,x,p[maxn],ans[maxn];
int buf[maxn],lbuf[maxn],rbuf[maxn];
ll tree[maxn];
vector<int>id[maxn];
struct quest
{	int l,r,val; }q[maxn];
void update(int pos,ll val)
{	while(pos<=m) tree[pos]+=val,pos+=lowbit(pos); }
void modify(int l,int r,ll val)
{
	if(l<=r) update(l,val),update(r+1,-val);
	else modify(1,r,val),modify(l,m,val);
}
ll query(int pos)
{
	ll ans=0;
	while(pos) ans+=tree[pos],pos-=lowbit(pos);
	return ans;
}
void solve(int L,int R,int l,int r)
{
	if(l==r)
	{
		for(int i=L;i<=R;i++) ans[buf[i]]=l;
		return;
	}
	int mid=(l+r)>>1,lsz=0,rsz=0;
	for(int i=l;i<=mid;i++) 
		modify(q[i].l,q[i].r,q[i].val);
	for(int i=L;i<=R;i++)
	{
		int pt=buf[i],&np=p[pt]; ll tmp=0;
		for(int j:id[pt])
			if((tmp+=query(j))>=np) break;
		if(tmp>=np) lbuf[lsz++]=pt;
		else np-=tmp,rbuf[rsz++]=pt;
	}
	for(int i=l;i<=mid;i++)
		modify(q[i].l,q[i].r,-q[i].val);
	memcpy(buf+L,lbuf,lsz*sizeof(int));
	memcpy(buf+L+lsz,rbuf,rsz*sizeof(int));
	solve(L,L+lsz-1,l,mid);
	solve(L+lsz,R,mid+1,r);
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
		scanf("%d",&x),id[x].push_back(i);
	for(int i=1;i<=n;i++)
		scanf("%d",&p[i]),buf[i]=i;
	scanf("%d",&k);
	for(int i=1;i<=k;i++)
		scanf("%d%d%d",&q[i].l,&q[i].r,&q[i].val);
	solve(1,n,1,k+1);
	for(int i=1;i<=n;i++)
		if(ans[i]<=k) printf("%d\n",ans[i]);
		else puts("NIE");		
}