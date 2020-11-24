#include<bits/stdc++.h>
using namespace std;
const int maxn=4e5+5;
int w[maxn],idx[maxn],ans;
vector<int>e[maxn];
struct WSegTree
{
	int tot,lrt[maxn*40],rrt[maxn*40],cnt[maxn*40];
	int merge(int x,int y,int l,int r)
	{
		if(!x||!y) return x|y;
		int mid=(l+r)>>1,rt=++tot;
		if(l==r) return cnt[rt]=cnt[x]+cnt[y],rt;
		lrt[rt]=merge(lrt[x],lrt[y],l,mid);
		rrt[rt]=merge(rrt[x],rrt[y],mid+1,r);
		cnt[rt]=cnt[lrt[rt]]+cnt[rrt[rt]];
		return rt;
	}
	void update(int& rt,int l,int r,int pos,int val)
	{
		if(!rt) rt=++tot;
		cnt[rt]+=val;
		if(l==r) return;
		int mid=(l+r)>>1;
		if(pos<=mid) update(lrt[rt],l,mid,pos,val);
		else update(rrt[rt],mid+1,r,pos,val);
	}
	int find(int rt,int l,int r,int pos)
	{
		if(!rt) return 0;
		if(l==r) return cnt[rt]?l:0;
		int mid=(l+r)>>1,ans;
		if(pos<=mid) ans=find(lrt[rt],l,mid,pos);
		else
		{
			ans=find(rrt[rt],mid+1,r,pos);
			if(!ans) ans=find(lrt[rt],l,mid,pos);
		}
		return ans;
	}
}t;
int dfs(int u,int n)
{
	int rt=0;
	for(int i=0;i<(int)e[u].size();i++)
	{
		int v=e[u][i];
		rt=t.merge(rt,dfs(v,n),1,n);
	}
	t.update(rt,1,n,w[u],1);
	int pos=t.find(rt,1,n,w[u]-1);
	if(pos&&w[u]>1) t.update(rt,1,n,pos,-1);
	return rt;
}
int main()
{
	int n,u,tot,rt;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&w[i]),idx[i]=w[i];
	sort(idx+1,idx+n+1);
	tot=unique(idx+1,idx+n+1)-idx-1;
	for(int i=1;i<=n;i++)
		w[i]=lower_bound(idx+1,idx+tot+1,w[i])-idx;
	for(int i=2;i<=n;i++)
		scanf("%d",&u),e[u].push_back(i);
	rt=dfs(1,tot),printf("%d",t.cnt[rt]);
}