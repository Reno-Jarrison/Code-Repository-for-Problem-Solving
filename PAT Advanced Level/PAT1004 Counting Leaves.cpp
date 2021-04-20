#include<bits/stdc++.h>
using namespace std;
const int maxn=105;
vector<int>e[maxn];
int leaf[maxn],mxv;
void dfs(int u,int lv)
{
	mxv=max(mxv,lv);
	if(!e[u].size()) leaf[lv]++;
	for(int v:e[u])
		dfs(v,lv+1);
}
int main()
{
	int n,m,u,k,v;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&u,&k);
		for(int j=1;j<=k;j++)
			scanf("%d",&v),e[u].push_back(v);
	}
	dfs(1,0);
	for(int i=0;i<=mxv;i++)
		printf("%d%c",leaf[i],i==mxv?'\n':' ');
}