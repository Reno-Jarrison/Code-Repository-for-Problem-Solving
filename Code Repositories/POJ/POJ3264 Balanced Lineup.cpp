#include<iostream>
using namespace std;
const int Maxn=50005;
struct node
{
	int left,right,min,max;
}tree[Maxn<<2];
int num[Maxn],minn,maxn;
void build(int left,int right,int root)
{
	tree[root].left=left,tree[root].right=right;
	if(left==right)
		tree[root].min=tree[root].max=num[right];
	else
	{
		int mid=(left+right)>>1,lson=root<<1,rson=lson+1;
		build(left,mid,lson);
		build(mid+1,right,rson);
		tree[root].max=max(tree[lson].max,tree[rson].max);
		tree[root].min=min(tree[lson].min,tree[rson].min);
	}
}
void query(int left,int right,int root)
{
	if(left==tree[root].left&&right==tree[root].right)
		maxn=max(maxn,tree[root].max),minn=min(minn,tree[root].min);
	else
	{
		int mid=(tree[root].left+tree[root].right)>>1,lson=root<<1,rson=lson+1;
		if(right<=mid)
			query(left,right,lson);
		else if(left>=mid+1)
			query(left,right,rson);
		else
			query(left,mid,lson),query(mid+1,right,rson);
	}
}
int main()
{
	int n,q,l,r;
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
		scanf("%d",&num[i]);
	build(1,n,1);
	for(int i=0;i<q;i++)
		maxn=-INT_MAX,minn=INT_MAX,scanf("%d%d",&l,&r),query(l,r,1),printf("%d\n",maxn-minn);
}