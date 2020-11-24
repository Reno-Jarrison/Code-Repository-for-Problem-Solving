#include<bits/stdc++.h>
using namespace std;
const int maxn=2e3+5;
int g[maxn][maxn],h[maxn][maxn],ans[maxn][maxn];
struct node
{
	int h,x;
	node(int h,int x):h(h),x(x){}
};
int main()
{
	int x,y,n,q,x1,x2,y1,y2;
	scanf("%d%d%d%d",&x,&y,&n,&q);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d%d",&x1,&x2,&y1,&y2);
		for(int i=x1+1;i<=x2;i++)
			for(int j=y1+1;j<=y2;j++)
				g[i][j]=1;
	}
	for(int i=1;i<=x;i++)
	{
		for(int j=1;j<=y;j++)
			h[i][j]=g[i][j]?0:h[i-1][j]+1;
		stack<node>stk;
		for(int j=1;j<=y+1;j++)
		{
			node cur=node(h[i][j],j);
			while(!stk.empty()&&cur.h<=stk.top().h)
			{	
				ans[stk.top().h][j-cur.x]--;
				cur.x=stk.top().x;
				ans[stk.top().h][j-cur.x]++;
				stk.pop();
			}
			ans[h[i][j]][j-cur.x]--;
			stk.push(cur);
		}
	}
	for(int i=1;i<=x;i++)
		for(int j=y-1;j;j--)
			ans[i][j]+=ans[i][j+1];
	for(int i=x;i;i--)
		for(int j=y;j;j--)
			ans[i][j]+=ans[i+1][j]+ans[i][j+1]-ans[i+1][j+1];
	while(q--)
	{
		scanf("%d%d",&x1,&y1);
		printf("%d\n",ans[x1][y1]);
	}
}