#include<bits/stdc++.h>
using namespace std;
int len[65],vis[65],tot;
bool dfs(int res,int cur,int pos)
{
	if(!res) return true;
	if(cur==tot)
	{	if(dfs(res-1,0,pos)) return true; }
	if(!pos) return false;
	for(int i=pos;i;i--)
		if(!vis[i]&&cur+len[i]<=tot)
		{
			vis[i]=1;
			int ok=dfs(res,cur+len[i],pos-(i==pos));
			vis[i]=0;
			if(ok) return true;
			if(cur+len[i]==tot||!cur) return false;
			while(len[i]==len[i-1]) i--;
		}
	return false;
}
int main()
{
	int n;
	while(scanf("%d",&n)&&n)
	{
		int sum=0;
		for(int i=1;i<=n;i++)
			scanf("%d",&len[i]),sum+=len[i];
		sort(len+1,len+n+1);
		for(int i=len[n];i<=sum;i++)
		{
			if(sum%i) continue;
			memset(vis,0,sizeof(vis)),tot=i;
			if(dfs(sum/i,0,n)) { printf("%d\n",i); break; }
		}
	}
}