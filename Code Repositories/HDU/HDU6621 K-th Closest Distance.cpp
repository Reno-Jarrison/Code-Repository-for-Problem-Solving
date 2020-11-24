#include<cstdio>
#include<vector>
#include<algorithm>
#define ll long long
using namespace std;
const int maxn=1e5+5;
int a[maxn];
vector<int>t[maxn<<2];
vector<int>::iterator it;
void build(int rt,int l,int r)
{
	t[rt].clear();
	for(int i=l;i<=r;i++)
		t[rt].push_back(a[i]);
	sort(t[rt].begin(),t[rt].end());
	if(l==r) return;
	int lson=rt<<1,rson=lson|1,mid=(l+r)>>1;
	build(lson,l,mid),build(rson,mid+1,r); 
}
int query(int rt,int l,int r,int L,int R,int val)
{
	if(L<=l&&r<=R)
	{
		it=upper_bound(t[rt].begin(),t[rt].end(),val);
		return it-t[rt].begin();
	}
	int lson=rt<<1,rson=lson|1,mid=(l+r)>>1,ans=0;
	L<=mid?ans+=query(lson,l,mid,L,R,val):false;
	R>mid?ans+=query(rson,mid+1,r,L,R,val):false;
	return ans;
}
int main()
{
	int t,m,n;
	scanf("%d",&t);
	while(t--)
	{
		int l,r,p,k,x=0,maxm=0;
		scanf("%d%d",&n,&m); 
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]),maxm=max(maxm,a[i]);
		build(1,1,n);
		for(int i=1;i<=m;i++)
		{
			scanf("%d%d%d%d",&l,&r,&p,&k);
			l^=x,r^=x,p^=x,k^=x;
			int left=0,right=maxm,mid,ans;
			while(left<=right)
			{
				mid=(left+right)>>1;
				ans=query(1,1,n,l,r,p+mid)-query(1,1,n,l,r,p-mid-1);
				ans<k?left=mid+1:right=mid-1;
			}
			printf("%d\n",x=left);
		} 
	}
}
