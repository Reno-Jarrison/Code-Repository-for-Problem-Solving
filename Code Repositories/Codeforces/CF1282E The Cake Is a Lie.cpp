#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e5+5;
struct node
{
	int u,v;
	node(int ux,int vx)
	{	if(ux>vx) swap(ux,vx); u=ux,v=vx; }
};
int s,cnt,idx,deg[maxn],vis[maxn];
vector<node>id;
vector<int>e[2][maxn],v[maxn*3];
queue<int>q;
bool operator <(const node& x,const node& y)
{	return x.u<y.u||(x.u==y.u&&x.v<y.v); }
void link(int u,int v,int x)
{	e[x][u].push_back(v),e[x][v].push_back(u); }
void dfs(int u)
{
	if(vis[u]) return;
	vis[u]=true;
	cout<<u<<" ";
	for(int v:e[0][u]) dfs(v);
}
void bfs()
{
	while(!q.empty())
	{
		int u=q.front();
		q.pop(),vis[u]=true;
		cout<<u<<" ";
		for(int v:e[1][u])
		{
			if(vis[v]) continue;
			if(--deg[v]<=1) q.push(v),vis[v]=true;
		}
	}
}
int main()
{
	int t,n,x[3];
	cin>>t;
	while(t--)
	{
		cin>>n;
		map<node,int>mp;
		memset(deg,0,sizeof(deg));
		for(int i=1;i<=n-2;i++)
		{
			for(int j=0;j<3;j++) cin>>x[j];
			for(int j=0;j<3;j++)
			{
				node tmp=node(x[j],x[(j+1)%3]);
				if(!mp.count(tmp)) 
					id.push_back(tmp),idx=cnt++,mp[tmp]=idx;
				idx=mp[tmp];
				v[idx].push_back(i);
			}
		}
		for(int i=1;i<=n;i++)
			e[0][i].clear(),e[1][i].clear();
		for(int i=0;i<(int)id.size();i++)
			if(v[i].size()==1) link(id[i].u,id[i].v,0);
			else
			{
				link(v[i][0],v[i][1],1);
				deg[v[i][0]]++,deg[v[i][1]]++;
			} 
		memset(vis,0,sizeof(vis)),dfs(1),puts("");
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=n-2;i++)
			if(deg[i]==1) q.push(i),vis[i]=true;
		if(n==3) cout<<1; 
		bfs(),puts("");
		for(int i=0;i<cnt;i++) v[i].clear();
		cnt=0,id.clear();
	}
}