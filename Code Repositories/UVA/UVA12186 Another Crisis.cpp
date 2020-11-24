#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
vector<int>e[maxn];
int t;
int dfs(int u)
{
	int k=e[u].size();
	if(!k) return 1;
	vector<int>vec;
	for(int v:e[u])
		vec.push_back(dfs(v));
	sort(vec.begin(),vec.end());
	int ans=0;
	for(int i=0;i<k;i++)
	{
		ans+=vec[i];
		if((i+1)*100>=k*t) break;
	}
	return ans;
}
int main()
{
	int n,u;
	while(~scanf("%d%d",&n,&t)&&n)
	{
		for(int i=0;i<=n;i++) e[i].clear();
		for(int v=1;v<=n;v++)
			scanf("%d",&u),e[u].push_back(v);
		printf("%d\n",dfs(0));
	}
}