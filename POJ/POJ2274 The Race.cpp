#include<iostream>
#include<cstdio>
#include<queue>
#define lowbit(x) ((x)&(-x))
using namespace std;
const int maxn=3e5+5,mod=1e6;
struct BIT
{
	int tree[105];
	void update(int x,int val)
	{
		for(int i=x;i<=100;i+=lowbit(i))
			tree[i]+=val;
	}
	int query(int x)
	{
		int ans=0;
		for(int i=x;i;i-=lowbit(i))
			ans+=tree[i];
		return ans;
	}
}t;
struct node
{
	int l,r; double t,p;
	node(int l,int r,double t,double p):
		l(l),r(r),t(t),p(p){}
};
bool operator <(const node& a,const node& b)
{	return a.t>b.t||(a.t==b.t&&a.p>b.p); }
priority_queue<node>hp;
int x[maxn],v[maxn],pre[maxn],suc[maxn];
void insert(int l,int r)
{
	if(v[l]<=v[r]) return;
	double t=1.0*(x[r]-x[l])/(v[l]-v[r]);
	hp.push(node(l,r,t,x[l]+v[l]*t));
}
int main()
{
	int n,ans=0,cnt=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&x[i],&v[i]);
		ans=(ans+t.query(100)-t.query(v[i]))%mod;
		t.update(v[i],1);
		pre[i]=i-1,suc[i]=i+1;
	}
	printf("%d\n",ans);
	for(int i=1;i<n;i++) insert(i,i+1);
	while(!hp.empty()&&cnt<10000)
	{
		node cur=hp.top(); hp.pop();
		int l=cur.l,r=cur.r,p=pre[l],s=suc[r];
		if(suc[l]!=r||pre[r]!=l) continue;
		pre[r]=p,suc[p]=r,suc[r]=l;
		suc[l]=s,pre[s]=l,pre[l]=r;
		if(p>=1) insert(p,r);
		if(s<=n) insert(l,s);
		printf("%d %d\n",l,r),cnt++;
	}
}