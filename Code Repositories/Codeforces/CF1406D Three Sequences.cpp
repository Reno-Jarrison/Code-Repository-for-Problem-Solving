#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e5+5;
ll d[maxn],sum,las,x;
void solve(ll x)
{	printf("%lld\n",(x>>1)+(x&1)); }
void update(int pos,ll val,int n)
{
	if(pos>n) return;
	if(pos==1) 
	{	d[1]+=val; return; }
	if(d[pos]>0) sum-=d[pos];
	d[pos]+=val;
	if(d[pos]>0) sum+=d[pos];
}
int main()
{
	int n,q,l,r;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",&x),d[i]=x-las,las=x;
	for(int i=2;i<=n;i++)
		if(d[i]>0) sum+=d[i];
	solve(d[1]+sum);
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d%d%lld",&l,&r,&x);
		update(l,x,n),update(r+1,-x,n),solve(d[1]+sum);
	}
}