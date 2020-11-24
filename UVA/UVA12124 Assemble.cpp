#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e3+5;
struct node
{
	ll cost,qual;
	node(ll a,ll b):cost(a),qual(b){}
};
int idx;
vector<node>p[maxn];
bool check(ll mval,ll lim)
{
	ll ans=0;
	for(int i=1;i<=idx;i++)
	{
		ll tmp=lim+1;
		for(node j:p[i]) if(j.qual>=mval) 
			tmp=min(tmp,j.cost);
		if((ans+=tmp)>lim) return false;
	}
	return true;
}
int main()
{
	ios::sync_with_stdio(false);
	int T,n;
	cin>>T;
	while(T--)
	{
		ll b,mxv=0,u,v;
		string x,y; 
		map<string,int>id;
		cin>>n>>b,idx=0;
		for(int i=1;i<=n;i++) p[i].clear();
		for(int i=1;i<=n;i++)
		{
			cin>>x>>y>>u>>v;
			if(!id[x]) id[x]=++idx;
			mxv=max(mxv,v);
			p[id[x]].push_back(node(u,v));
		}
		ll l=1,r=mxv;
		while(l<=r)
		{
			ll mid=(l+r)>>1;
			if(check(mid,b)) l=mid+1;
			else r=mid-1;
		}
		cout<<r<<endl;
	}
}