#include<iostream>
#include<climits>
#define ll long long
#define maxn 200005
#define init mid=(tree[root].left+tree[root].right)>>1,lson=root<<1,rson=lson|1
using namespace std;
struct node
{
	int left,right;
	ll maxm;
}tree[maxn<<2];
ll m,mod,last,x,cnt;
void build(int root,int left,int right)
{
	tree[root].left=left;
	tree[root].right=right;
	tree[root].maxm=-INT_MAX;
	if(left==right) return;
	int init;
	build(lson,left,mid);
	build(rson,mid+1,right);
}
void update(int root,int left,int right,ll val)
{
	if(tree[root].left==left&&tree[root].right==right)
		{ tree[root].maxm=val%mod; return; }
	else
	{
		int init;
		if(left>mid)
			update(rson,left,right,val);
		else if(right<=mid)
			update(lson,left,right,val);
		else
			update(rson,mid+1,right,val),update(lson,left,mid,val);
		tree[root].maxm=max(tree[lson].maxm,tree[rson].maxm);
	}
}
ll query(int root,int left,int right)
{
	if(tree[root].left==left&&tree[root].right==right)
		return tree[root].maxm;
	int init;
	if(right<=mid) return query(lson,left,right); 
	else if(left>mid) return query(rson,left,right); 
	return max(query(lson,left,mid),query(rson,mid+1,right));
}
int main()
{
	char ope;
	cin>>m>>mod;
	build(1,1,m);
	for(int i=0;i<m;i++) 
	{
		cin>>ope>>x;
		if(ope=='A')
			cnt++,update(1,cnt,cnt,last%mod+x%mod);
		else
			cout<<(last=query(1,cnt-x+1,cnt))<<endl;
	}
}