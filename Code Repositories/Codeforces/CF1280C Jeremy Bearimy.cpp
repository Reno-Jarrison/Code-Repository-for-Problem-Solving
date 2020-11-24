#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2e5+5;
struct edge
{
	int v,id;
	edge(int v,int id):v(v),id(id){}
};
vector<edge>e[maxn];
void link(int u,int v,int id)
{
	e[u].push_back(edge(v,id));
	e[v].push_back(edge(u,id));
}
int siz[maxn],cnt[maxn],cost[maxn],k;
void dfs(int u,int f,int id)
{
	siz[u]=u>1;
	for(edge x:e[u]) if(x.v!=f)
	{
		dfs(x.v,u,x.id);
		siz[u]+=siz[x.v];
	}
	cnt[id]=min(siz[u],k-siz[u]);
}
int main()
{
	int t,u,v,w;
	cin>>t;
	while(t--)
	{
		cin>>k,k<<=1;
		for(int i=1;i<=k;i++) e[i].clear();
		for(int i=1;i<k;i++)
			cin>>u>>v>>w,link(u,v,i),cost[i]=w;
		dfs(1,0,0);
		ll mnv=0,mxv=0;
		for(int i=1;i<k;i++)
			mnv+=1LL*cost[i]*(cnt[i]&1),mxv+=1LL*cost[i]*cnt[i];
		cout<<mnv<<" "<<mxv<<endl;
	}
}