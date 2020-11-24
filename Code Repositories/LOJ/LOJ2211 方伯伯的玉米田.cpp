#include<bits/stdc++.h>
#define lowbit(x) ((x)&(-x))
using namespace std;
const int maxn=1e4+5,maxm=6e3+5;
int h[maxn],tree[maxm][505],mxr,mxc;
void update(int x,int y,int val)
{
	for(int i=x;i<=mxr;i+=lowbit(i))
		for(int j=y;j<=mxc;j+=lowbit(j))
			tree[i][j]=max(tree[i][j],val);
}
int query(int x,int y)
{
	int ans=0;
	for(int i=x;i;i-=lowbit(i))
		for(int j=y;j;j-=lowbit(j))
			ans=max(ans,tree[i][j]);
	return ans;
}
int main()
{
	int n,k,ans=0;
	scanf("%d%d",&n,&k),mxc=k+1;
	for(int i=1;i<=n;i++)
		scanf("%d",&h[i]),mxr=max(mxr,h[i]+k);
	for(int i=1;i<=n;i++)
		for(int j=k;~j;j--)
		{
			int tmp=query(h[i]+j,j+1)+1;
			ans=max(ans,tmp);
			update(h[i]+j,j+1,tmp);
		}
	printf("%d\n",ans);
}