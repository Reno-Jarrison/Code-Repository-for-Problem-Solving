#include<cstdio>
#include<cstring>
#define ll long long
#define lowbit(x) (x)&(-x)
using namespace std;
const int maxn=5e3+5;
bool tree[maxn][maxn];
void update(int x,int y,int n,int m)
{
	for(int i=x;i<=n;i+=lowbit(i))
		for(int j=y;j<=m;j+=lowbit(j))
			tree[i][j]^=1;
}
bool query(int x,int y)
{
	bool ans=0;
	for(int i=x;i;i-=lowbit(i))
		for(int j=y;j;j-=lowbit(j))
			ans^=tree[i][j];
	return ans;
}
void modify(int x1,int y1,int x2,int y2,int n,int m)
{
	update(x1,y1,n,m),update(x2+1,y2+1,n,m);
	update(x1,y2+1,n,m),update(x2+1,y1,n,m);
}
int main()
{
	int t,n,m,q,x1,y1,x2,y2,first;
	char o[3];
	scanf("%d",&t);
	while(t--)
	{
		memset(tree,0,sizeof(tree));
		if(first++) puts("");
		scanf("%d%d",&n,&q),m=n;
		while(q--)
		{
			scanf("%s",o);
			if(o[0]=='C') 
			{
				scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
				modify(x1,y1,x2,y2,n,m);
			}
			if(o[0]=='Q') scanf("%d%d",&x1,&y1),printf("%d\n",query(x1,y1));
		}
	}
}
