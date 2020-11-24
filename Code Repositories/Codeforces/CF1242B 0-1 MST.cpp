#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
set<int>e[maxn],st; 
bool flag[maxn];
void link(int u,int v)
{	e[u].insert(v),e[v].insert(u); }
void dfs(int u)
{
	flag[u]=true;
	vector<int>tmp;
	for(int v:st) if(!e[u].count(v))
		tmp.push_back(v);
	for(int v:tmp) st.erase(v);
	for(int v:tmp) dfs(v);
}
int main()
{
	int n,m,u,v,ans=0;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
		cin>>u>>v,link(u,v);
	for(int i=1;i<=n;i++) st.insert(i); 
	for(int i=1;i<=n;i++) if(!flag[i]) 
		ans++,st.erase(i),dfs(i);
	cout<<ans-1;
}
