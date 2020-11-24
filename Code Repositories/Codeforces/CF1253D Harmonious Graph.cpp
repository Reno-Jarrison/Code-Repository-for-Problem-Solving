#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int cnt,id[maxn],f[maxn],vis[maxn],mxv[maxn];
int find(int x)
{	return x==f[x]?x:f[x]=find(f[x]); }
bool merge(int x,int y)
{
	int fx=find(x),fy=find(y);
	if(fx==fy) return false;
	f[fy]=fx,mxv[fx]=max(mxv[fx],mxv[fy]);
	return true;
}
int main()
{
	int n,m,u,v,ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++) f[i]=mxv[i]=i;
	for(int i=1;i<=m;i++)
		cin>>u>>v,merge(u,v);
	for(int i=1;i<n;i++)
		if(mxv[find(i)]>i&&merge(i,i+1)) ans++;
	cout<<ans;
}

