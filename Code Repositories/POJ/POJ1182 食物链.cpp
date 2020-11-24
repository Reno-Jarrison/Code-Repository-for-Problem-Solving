#include<cstdio>
#define ll long long
using namespace std;
const int maxn=5e4+5;
int f[maxn*3];
int find(int x)
{	return x==f[x]?x:f[x]=find(f[x]); }
void join(int x,int y)
{	f[find(x)]=find(y); }
int main()
{
	int n,k,flag,x,y,ans=0;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n*3;i++) f[i]=i;
	for(int i=1;i<=k;i++)
	{
		scanf("%d%d%d",&flag,&x,&y);
		if(x>n||y>n) { ans++; continue; }
		if(flag==1)
		{
			if(find(x+n)==find(y)||find(x+n*2)==find(y))
			{	ans++; continue; }
			join(x,y),join(x+n,y+n),join(x+n*2,y+n*2);
		}
		else
		{
			if(find(x)==find(y)||find(x+n*2)==find(y))
			{	ans++; continue; }
			join(x+n,y),join(x+n*2,y+n),join(x,y+n*2);
		}
	}
	printf("%d",ans);
}
