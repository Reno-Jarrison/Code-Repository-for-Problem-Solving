#include<bits/stdc++.h>
#define lson(rt) son[rt][0]
#define rson(rt) son[rt][1]
using namespace std;
const int maxn=1e5+5,inf=0x3f3f3f3f;
struct Splay
{
	int tot,root,son[maxn][2],fat[maxn];
	int siz[maxn],w[maxn],cnt[maxn];
	void clear()
	{	tot=-1,root=newnode(0,0),siz[0]=cnt[0]=0; }
	int newnode(int val,int f)
	{
		w[++tot]=val,cnt[tot]=siz[tot]=1;
		lson(tot)=rson(tot)=0,fat[tot]=f;
		if(f) son[f][val>w[f]]=tot;
		return tot;
	}
	int getdir(int rt)
	{	return rson(fat[rt])==rt; }
	void push_up(int rt)
	{	siz[rt]=siz[lson(rt)]+siz[rson(rt)]+cnt[rt]; }
	void connect(int x,int f,int dir)
	{	fat[x]=f,son[f][dir]=x; }
	void rotate(int rt)
	{
		int f=fat[rt],gf=fat[f];
		int xdir=getdir(rt),fdir=getdir(f);
		connect(son[rt][!xdir],f,xdir);
		connect(f,rt,!xdir);
		connect(rt,gf,fdir);
		push_up(f),push_up(rt);
	}
	void splay(int rt,int dst)
	{
		while(fat[rt]!=dst)
		{
			int f=fat[rt],gf=fat[f];
			int xdir=getdir(rt),fdir=getdir(f);
			if(gf!=dst) rotate(xdir==fdir?f:rt);
			rotate(rt);
		}
		if(!dst) root=rt;
	}
	void insert(int val)
	{
		int rt=root,f=0;
		while(rt&&val!=w[rt])
			f=rt,rt=son[rt][val>w[rt]];
		if(rt) cnt[rt]++;
		else rt=newnode(val,f);
		splay(rt,0);
	}
	int find(int val)
	{
		int rt=root;
		while(rt)
		{
			if(val==w[rt])
			{	splay(rt,0); break; }
			rt=son[rt][val>w[rt]];
		}
		return rt;
	}
	int getpre(int val)
	{
		int rt=root,ans=-inf,pre=rt;
		while(rt)
		{
			if(val>w[rt]&&ans<w[rt]) 
				ans=w[rt],pre=rt;
			rt=son[rt][val>w[rt]];
		}
		if(pre) splay(pre,0);
		return ans;
	}
	int getkth(int k)
	{
		int rt=root;
		while(true)
		{
			int rsiz=siz[rson(rt)];
			if(k<=rsiz) rt=rson(rt);
			else if(k>rsiz+cnt[rt])
				k-=rsiz+cnt[rt],rt=lson(rt);
			else return splay(rt,0),w[rt];
		}
	}
}t;
int main()
{
	int n,lim,x,delta=0,tot=0;
	char o[3];
	scanf("%d%d",&n,&lim);
	t.clear();
	while(n--)
	{
		scanf("%s%d",o,&x);
		if(o[0]=='I'&&x>=lim)
			t.insert(x-delta);
		if(o[0]=='A') delta+=x;
		if(o[0]=='S')
		{
			delta-=x;
			int pre=t.getpre(lim-delta);
			if(pre==-inf) continue;
			tot+=t.siz[t.lson(t.root)]+t.cnt[t.root];
			t.root=t.rson(t.root),t.fat[t.root]=0;
		}
		if(o[0]=='F')
			printf("%d\n",x<=t.siz[t.root]?t.getkth(x)+delta:-1);
	}
	printf("%d\n",tot);
}