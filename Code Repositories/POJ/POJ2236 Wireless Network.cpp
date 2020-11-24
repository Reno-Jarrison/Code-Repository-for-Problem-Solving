#include<cstdio>
using namespace std;
const int maxn=1e3+5;
int f[maxn],px[maxn],py[maxn],tag[maxn];
int sqr(int x)
{	return x*x; }
int dist(int a,int b)
{	return sqr(px[a]-px[b])+sqr(py[a]-py[b]); }
int find(int x)
{	return f[x]==x?x:f[x]=find(f[x]); }
int main()
{
	int n,d,x,u,v;
	scanf("%d%d",&n,&d);
	for(int i=1;i<=n;i++) 
		scanf("%d%d",&px[i],&py[i]),f[i]=i;
	char s[2];
	while(~scanf("%s",s))
	{
		if(s[0]=='O')
		{
			scanf("%d",&x),tag[x]=1;
			int fx=find(x);
			for(int j=1;j<=n;j++)
			{
				if(j==x||!tag[j]) continue;
				if(dist(x,j)>d*d) continue;
				int fy=find(j);
				if(fx!=fy) f[fy]=fx; 
			}
		}
		else
		{
			scanf("%d%d",&u,&v);
			puts(find(u)==find(v)?"SUCCESS":"FAIL");
		}
	}
}