#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2e3+5;
ll x[maxn],y[maxn];
int vec[maxn];
ll sqr(ll x)
{	return x*x; }
ll getdis(int i,int j)
{	return sqr(x[i]-x[j])+sqr(y[i]-y[j]); }
int main()
{
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		set<int>st;
		for(int i=1;i<=n;i++)
			scanf("%lld%lld",&x[i],&y[i]),st.insert(i);
		int ok=0;
		while(true)
		{
			int tot=0;
			set<int>buf;
			for(int x:st) vec[++tot]=x;
			if(tot==1) break;
			ll mxv=0;
			for(int i=1;i<=tot;i++)
				for(int j=i+1;j<=tot;j++)
				{
					ll cur=getdis(vec[i],vec[j]);
					if(cur>mxv)
					{
						mxv=cur,buf.clear();
						buf.insert(vec[i]);
						buf.insert(vec[j]);
					}
					else if(cur==mxv)
						buf.insert(vec[i]),buf.insert(vec[j]);
				}
			if(buf.count(1)) 
			{	ok=1; break; }
			for(int x:buf) st.erase(x);
		}
		puts(ok?"YES":"NO");
	}
}