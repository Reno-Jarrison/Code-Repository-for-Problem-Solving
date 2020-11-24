#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
vector<int>e[maxn];
set<int>st,to[maxn];
void link(int u,int v)
{	e[u].push_back(v); }
void dfs(int u,int s)
{
	if(to[u].size()>1||to[u].count(s)) return;
	to[u].insert(s);
	for(int v:e[u]) dfs(v,s);
}
int main()
{
	int n,m,t,u,v;
	scanf("%d%d%d",&n,&m,&t);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&u,&v);
		if(v!=t) link(v,u);
		else st.insert(u);
	}
	for(int x:st) dfs(x,x);
	vector<int>ans;
	for(int x:st) 
		if(to[x].size()==1) ans.push_back(x);
	printf("%d\n",(int)ans.size());
	for(int x:ans) printf("%d\n",x);
}