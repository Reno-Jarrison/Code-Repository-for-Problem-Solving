#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+5,maxm=2e4+5;
vector<int>e[maxn];
int f[maxn],eu[maxm],ev[maxm],ind[maxn],vis[maxn],ok;
int find(int x)
{	return f[x]==x?x:f[x]=find(f[x]); }
bool top_sort(int n)
{
	queue<int>que;
	for(int i=0;i<n;i++)
	{
		int x=find(i);
		if(!ind[x]&&!vis[x]) 
			que.push(x),vis[x]=1;
	}
	int ans=true;
	while(!que.empty())
	{
		if(que.size()>1) ans=false;
		int u=que.front(); que.pop();
		vis[u]=1;
		for(int v:e[u])
			if(!--ind[v]) que.push(v);
	}
	for(int i=0;i<n;i++)
		if(!vis[find(i)]) ok=0;
	return ans;
}
int main()
{
	int n,m,u,v;
	while(~scanf("%d%d",&n,&m))
	{
		for(int i=0;i<n;i++) 
			f[i]=i,ind[i]=0,vis[i]=0,e[i].clear();
		int idx=0;
		for(int i=1;i<=m;i++)
		{
			char s[2];
			scanf("%d%s%d",&u,s,&v);
			if(s[0]=='=')
			{
				int fu=find(u),fv=find(v);
				if(fu!=fv) f[fu]=fv;
				continue;
			}
			else if(s[0]=='<') swap(u,v);
			eu[++idx]=u,ev[idx]=v;
		}
		ok=1;
		for(int i=1;i<=idx;i++)
		{
			int fu=find(eu[i]),fv=find(ev[i]);
			if(fu==fv) ok=0;
			e[fu].push_back(fv),ind[fv]++;
		}
		int tag=top_sort(n);
		if(!ok) puts("CONFLICT");
		else if(!tag) puts("UNCERTAIN");
		else puts("OK");
	}
}