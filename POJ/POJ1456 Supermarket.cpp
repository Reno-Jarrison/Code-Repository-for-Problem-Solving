#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e4+5;
struct node
{	int x,t; }p[maxn];
int f[maxn];
bool operator <(const node& a,const node& b)
{	return a.x>b.x; }
int find(int x)
{	return x==f[x]?x:f[x]=find(f[x]); }
int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		int lim=0,ans=0;
		for(int i=1;i<=n;i++)
			scanf("%d%d",&p[i].x,&p[i].t),lim=max(lim,p[i].t);
		sort(p+1,p+n+1);
		for(int i=0;i<=lim;i++) f[i]=i;
		for(int i=1;i<=n;i++)
		{
			int las=find(p[i].t);
			if(!las) continue;
			ans+=p[i].x;
			f[las]=find(las-1);
		}
		printf("%d\n",ans);
	}
}