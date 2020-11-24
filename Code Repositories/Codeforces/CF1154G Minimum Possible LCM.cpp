#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e7+5,inf=0x3f3f3f3f;
set<int>st[maxn];
ll gcd(ll a,ll b)
{	return !b?a:gcd(b,a%b); }
ll lcm(ll a,ll b)
{	return a/gcd(a,b)*b; }
int main()
{
	int n,a,idx1,idx2,mnv1=inf,mnv2=inf,lim=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a),st[a].insert(i),lim=max(lim,a);
		if(a<mnv1) idx2=idx1,mnv2=mnv1,idx1=i,mnv1=a;
		else if(a<mnv2) idx2=i,mnv2=a;
	}
	ll mnv=lcm(mnv1,mnv2);
	for(int i=2;i<=lim;i++)
	{
		int id1,id2,ok=0;
		mnv1=mnv2=inf;
		for(int j=i;!ok&&j<=lim;j+=i)
			for(int x:st[j])
			{
				if(mnv1==inf) id1=x,mnv1=j;
				else 
				{	id2=x,mnv2=j,ok=1; break; }
			}
		if(ok&&lcm(mnv1,mnv2)<mnv)
			idx1=id1,idx2=id2,mnv=lcm(mnv1,mnv2);
	}
	if(idx1>idx2) swap(idx1,idx2);
	printf("%d %d",idx1,idx2);
}