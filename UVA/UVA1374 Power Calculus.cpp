#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+5;
int num[maxn],vis[maxn<<1];
bool dfs(int d,int cur,int lim,int n)
{
	int mxv=0;
	for(int i=0;i<=d;i++)
		mxv=max(mxv,num[i]);
	if(mxv*(1<<(lim-d))<n) return false;
	if(cur==n) return true;
	for(int i=d;~i;i--)
	{
		int nxt1=cur+num[i],nxt2=abs(cur-num[i]);
		if(nxt1<=n*2&&!vis[nxt1])
		{
			vis[nxt1]=1,num[d+1]=nxt1;
			if(dfs(d+1,nxt1,lim,n)) return true;
			vis[nxt1]=0;
		}
		if(nxt2>=1&&!vis[nxt2])
		{
			vis[nxt2]=1,num[d+1]=nxt2;
			if(dfs(d+1,nxt2,lim,n)) return true;
			vis[nxt2]=0;
		}
	}
	return false;
}
int main()
{
	int n;
	while(scanf("%d",&n)&&n)
	{
		int dep=0;
		while(true)
		{	
			memset(vis,0,sizeof(vis));
			num[0]=1,vis[1]=1;
			if(dfs(0,1,dep,n)) break;
			dep++; 
		}
		printf("%d\n",dep);
	}
}