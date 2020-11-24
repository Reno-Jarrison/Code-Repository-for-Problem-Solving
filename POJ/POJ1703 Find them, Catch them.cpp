#include<iostream>
#define ll long long
using namespace std;
const int maxn=1e5+5;
int f[maxn<<1];
int find(int x)
{	return x==f[x]?x:f[x]=find(f[x]); }
void join(int x,int y)
{	f[find(x)]=find(y); } 
int main()
{
	ios::sync_with_stdio(false);
	int t,n,m,a,b;
	char o[5];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n<<1;i++) f[i]=i;
		for(int i=1;i<=m;i++)
		{
			scanf("%s%d%d",o,&a,&b);
			if(o[0]=='D') join(a,b+n),join(a+n,b);
			else if(find(a)==find(b))
				printf("In the same gang.\n");
			else if(find(a+n)==find(b))
				printf("In different gangs.\n");
			else printf("Not sure yet.\n");
		}
	}
}
