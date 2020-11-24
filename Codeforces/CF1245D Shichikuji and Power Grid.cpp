#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2e3+5;
const ll inf=0x3f3f3f3f3f3f3f3f;
int vtx[maxn];
ll x[maxn],y[maxn],c[maxn],k[maxn];
ll f[maxn],fc[maxn],ans;
bool flag[maxn*maxn];
struct edge
{
	int u,v; ll w;
	edge(int u,int v,ll w):u(u),v(v),w(w){}
};
bool operator <(const edge& a,const edge& b)
{	return a.w<b.w; }
vector<edge>e;
ll getcost(int a,int b)
{	return (k[a]+k[b])*(abs(x[a]-x[b])+abs(y[a]-y[b])); }
int find(int a)
{	return f[a]==a?a:f[a]=find(f[a]); }
void merge(int a,int b)
{	f[a]=b; }
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>x[i]>>y[i],f[i]=i;
	for(int i=1;i<=n;i++) cin>>c[i],ans+=c[i],fc[i]=c[i];	
	for(int i=1;i<=n;i++) cin>>k[i];
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			e.push_back(edge(i,j,getcost(i,j)));
	sort(e.begin(),e.end());
	int siz=e.size(),ecnt=0,vcnt=n;
	for(int i=0;i<siz;i++)
	{
		int u=e[i].u,v=e[i].v; ll w=e[i].w;
		int fu=find(u),fv=find(v);
		if(fu==fv) continue;
		if(w<max(fc[fu],fc[fv]))
		{
			merge(fu,fv),flag[i]=true;
			ecnt++,vcnt--;
			ans+=w-max(fc[fu],fc[fv]);
			fc[fu]=fc[fv]=min(fc[fu],fc[fv]);
		}
	}
	for(int i=1;i<=n;i++)
	{
		int fi=find(i);
		if(c[i]==fc[fi]) vtx[fi]=i;
	}
	cout<<ans<<endl<<vcnt<<endl;
	for(int i=1;i<=n;i++)
		if(vtx[i]) cout<<vtx[i]<<" ";
	cout<<endl<<ecnt<<endl;
	for(int i=0;i<siz;i++)
		if(flag[i])  cout<<e[i].u<<" "<<e[i].v<<endl;
}

