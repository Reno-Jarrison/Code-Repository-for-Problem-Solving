#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
vector<int>id[maxn];
vector<pair<int,int>>q[maxn];
int eu[maxn],ev[maxn],w[maxn],ok[maxn];
struct DSU
{
	int f[maxn],rk[maxn];
	stack<pair<int*,int>>stk;
	void init(int n)
	{
		for(int i=1;i<=n;i++)
			f[i]=i,rk[i]=0;
		while(!stk.empty()) stk.pop();
	}
	int find(int x)
	{	
		while(f[x]!=x) x=f[x];
		return x;
	}
	int merge(int u,int v)
	{
		int fu=find(u),fv=find(v);
		if(fu==fv) return 0;
		if(rk[fu]>rk[fv]) swap(fu,fv);
		stk.push(make_pair(f+fu,f[fu])),f[fu]=fv;
		if(rk[fu]!=rk[fv]) return 1;
		stk.push(make_pair(rk+fv,rk[fv])),rk[fv]++;
		return 2;
	}
	void undo()
	{	*stk.top().first=stk.top().second; stk.pop(); }
}dsu;
int main()
{
	int n,m,t,k,x,lim=0;
	scanf("%d%d",&n,&m);
	dsu.init(n);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&eu[i],&ev[i],&w[i]);
		id[w[i]].push_back(i);
		lim=max(lim,w[i]);
	}
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		scanf("%d",&k),ok[i]=1;
		for(int j=1;j<=k;j++)
		{
			scanf("%d",&x);
			q[w[x]].emplace_back(i,x);
		}
	}
	for(int i=1;i<=lim;i++)
	{
		int siz=q[i].size();
		for(int l=0,r=0;l<siz;l=r+1)
		{
			int qid=q[i][l].first,cnt=0;
			while(r+1<siz&&q[i][r+1].first==qid) r++;
			for(int j=l;j<=r;j++)
			{
				int idx=q[i][j].second,cur=dsu.merge(eu[idx],ev[idx]);
				if(!cur) ok[qid]=0;
				cnt+=cur;
			}
			while(cnt--) dsu.undo();
		}
		for(int x:id[i])
			dsu.merge(eu[x],ev[x]);
	}
	for(int i=1;i<=t;i++)
		puts(ok[i]?"YES":"NO");
}