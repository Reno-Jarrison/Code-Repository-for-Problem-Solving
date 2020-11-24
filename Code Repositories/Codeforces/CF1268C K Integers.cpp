#include<bits/stdc++.h>
#define ll long long
#define lowbit(x) ((x)&(-x))
using namespace std;
const int maxn=2e5+5;
int n,p[maxn],idx[maxn];
ll tree1[maxn],tree2[maxn];
priority_queue<int>lhp;
priority_queue<int,vector<int>,greater<int> >rhp;
void update(int x,int val)
{	while(x<=n) tree1[x]++,tree2[x]+=val,x+=lowbit(x); }
ll query(int x,ll* tree)
{
	ll ans=0;
	while(x) ans+=tree[x],x-=lowbit(x);
	return ans;
}
void insert(int x)
{
	if(!rhp.empty()&&x>=rhp.top())
	{
		lhp.push(rhp.top());
		rhp.pop(),rhp.push(x);
	}
	else lhp.push(x);
	if(rhp.size()+1<lhp.size())
		rhp.push(lhp.top()),lhp.pop();
}
ll sum(ll x)
{	return x*(x+1)/2; }
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i],idx[p[i]]=i;
	ll inv=0;
	for(int i=1;i<=n;i++)
	{
		update(idx[i],idx[i]),insert(idx[i]);
		int l=lhp.top(),r=l+1;
		int lcnt=query(l,tree1),rcnt=i-lcnt;
		inv+=i-query(idx[i],tree1);
		ll ans=inv+query(n,tree2)-2*query(l,tree2);
		ans+=l*lcnt-r*rcnt-sum(lcnt-1)-sum(rcnt-1);
		cout<<ans<<" ";
	}
}
