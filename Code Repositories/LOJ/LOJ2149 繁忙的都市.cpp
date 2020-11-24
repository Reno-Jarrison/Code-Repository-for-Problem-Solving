#include<cstdio>
#include<algorithm> 
using namespace std;
const int maxn=1e5+5; 
struct edge
{	int u,v,c; }e[maxn];
bool operator <(const edge& x,const edge& y)
{	return x.c<y.c; }
int f[305];
int find(int x)
{	return f[x]==x?x:f[x]=find(f[x]); }
int main()
{
	int n,m,ans,cnt=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
		scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].c);
	for(int i=1;i<=n;i++) f[i]=i; 
	sort(e+1,e+m+1);
	for(int i=1;i<=m&&cnt<n-1;i++)
	{
		int fx=find(e[i].u),fy=find(e[i].v);
		if(fx^fy) f[fx]=fy,ans=e[i].c,cnt++;
	}
	printf("%d %d",n-1,ans);
}