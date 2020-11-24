#include<bits/stdc++.h>
#define lson(rt) son[rt][0]
#define rson(rt) son[rt][1]
using namespace std;
const int maxn=4e4+5,inf=0x3f3f3f3f;
struct FHQTreap
{
	int root,tot,son[maxn][2];
	int w[maxn],key[maxn],siz[maxn];
	int newnode(int val)
	{
		w[++tot]=val,key[tot]=rand(),siz[tot]=1;
		return tot;
	}
	void push_up(int rt)
	{	siz[rt]=siz[lson(rt)]+siz[rson(rt)]+1; }
	void split_val(int rt,int val,int& x,int& y)
	{
		if(!rt) { x=y=0; return; }
		if(w[rt]<=val) x=rt,split_val(rson(rt),val,rson(rt),y);
		else y=rt,split_val(lson(rt),val,x,lson(rt));
		push_up(rt);
	}
	int merge(int x,int y)
	{
		if(!x||!y) return x|y;
		if(key[x]<key[y])
			return rson(x)=merge(rson(x),y),push_up(x),x;
		else return lson(y)=merge(x,lson(y)),push_up(y),y;
	}
	void insert(int val)
	{
		int x,y;
		split_val(root,val,x,y);
		root=merge(x,merge(newnode(val),y));
	}
	int getkth(int rt,int k)
	{
		while(true)
		{
			int lsiz=siz[lson(rt)];
			if(k<=lsiz) rt=lson(rt);
			else if(k>lsiz+1)
				k-=lsiz+1,rt=rson(rt);
			else return rt;
		}
	}
	int getpre(int val)
	{
		int x,y,ans;
		split_val(root,val,x,y);
		ans=siz[x]>1?w[getkth(x,siz[x]-1)]:-inf;
		root=merge(x,y);
		return ans;
	}
	int getsuc(int val)
	{
		int x,y,ans;
		split_val(root,val-1,x,y);
		ans=siz[y]>1?w[getkth(y,2)]:inf;
		root=merge(x,y);
		return ans;
	}
}t;
int main()
{
	int n,x,ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		t.insert(x);
		if(i==1) ans+=x;
		else ans+=min(x-t.getpre(x),t.getsuc(x)-x);
	}
	printf("%d",ans);
}	