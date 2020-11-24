#include<bits/stdc++.h>
#define ll long long
using namespace std;
int pcnt,p[50],vis[130];
void getprime()
{
	for(int i=2;i<128;i++)
	{
		if(!vis[i]) p[++pcnt]=i;
		for(int j=1;i*p[j]<128;j++)
		{
			vis[i*p[j]]=true;
			if(i%p[j]==0) break;
		}
	}
}
struct hpnode
{
	ll val;
	int k,lim,pf;
	hpnode(ll v,int k,int l,int p):val(v),k(k),lim(l),pf(p){}
};
bool operator <(const hpnode& x,const hpnode& y)
{	return x.val<y.val; }
priority_queue<hpnode>hp;
int main()
{
	ll n,k;
	scanf("%lld%lld",&n,&k);
	getprime();
	for(int i=1;i<=pcnt;i++)
	{
		ll val=p[i];
		for(int j=1;val<=n;j++)
			hp.push(hpnode(val,j,i-1,p[i])),val*=p[i];
	}
	while(--k)
	{
		hpnode cur=hp.top(); hp.pop();
		ll val=cur.val/cur.pf;
		if(cur.k>1) for(int i=cur.lim;i;i--)
			hp.push(hpnode(val*p[i],cur.k-1,i,cur.pf));
	}
	printf("%lld\n",hp.top().val);
}