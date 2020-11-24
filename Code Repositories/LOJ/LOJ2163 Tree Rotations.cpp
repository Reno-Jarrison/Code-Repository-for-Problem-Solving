#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2e5+5;
ll ans,ans1,ans2;
struct WSegtree
{
	int tot,cnt[maxn*25],lson[maxn*25],rson[maxn*25];
	void update(int& rt,int l,int r,int val)
	{
		if(!rt) rt=++tot;
		cnt[rt]++;
		if(l==r) return;
		int mid=(l+r)>>1;
		if(val<=mid) update(lson[rt],l,mid,val);
		else update(rson[rt],mid+1,r,val);
	}
	void merge(int &x,int y)
	{
		if(!x||!y)
		{	x=x|y; return; }
		cnt[x]+=cnt[y];
		ans1+=1LL*cnt[lson[x]]*cnt[rson[y]];
		ans2+=1LL*cnt[rson[x]]*cnt[lson[y]];
		merge(lson[x],lson[y]);
		merge(rson[x],rson[y]);
	}
}t;
void dfs(int& rt,int n)
{
	int x,lson,rson;
	scanf("%d",&x),rt=0;
	if(x) {	t.update(rt,1,n,x); return; }
	dfs(lson,n),dfs(rson,n);
	ans1=ans2=0;
	rt=lson,t.merge(rt,rson);
	ans+=min(ans1,ans2);
}
int main()
{
	int n,rt=0;
	scanf("%d",&n),dfs(rt,n);
	printf("%lld\n",ans);
}	