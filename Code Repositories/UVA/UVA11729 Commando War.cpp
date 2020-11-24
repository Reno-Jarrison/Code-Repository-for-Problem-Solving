#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+5;
struct node
{
	int b,j;
	friend bool operator <(const node& x,const node& y)
	{	return x.j>y.j||(x.j==y.j&&x.b<y.b); }
}p[maxn];
int main()
{
	int n,ks=0;
	while(scanf("%d",&n)&&n)
	{
		for(int i=1;i<=n;i++)
			scanf("%d%d",&p[i].b,&p[i].j);
		sort(p+1,p+n+1);
		int t1=0,t2=0;
		for(int i=1;i<=n;i++)
		{
			t1+=p[i].b;
			t2=max(t2,t1+p[i].j);
		}
		printf("Case %d: %d\n",++ks,t2);
	}
}