#include<bits/stdc++.h>
using namespace std;
int num[15],vis[15],buf[6],n;
void dfs(int las,int step)
{
	if(step==6)
	{
		for(int i=0;i<6;i++)
			printf("%d%c",buf[i],i==5?'\n':' ');
		return;
	}
	for(int i=las+1;i<=n;i++)
	{
		if(vis[i]) continue; 
		vis[i]=1,buf[step]=num[i];
		dfs(i,step+1),vis[i]=0;
	}
}
int main()
{
	int fst=1;
	while(scanf("%d",&n)&&n)
	{
		fst?fst=0:puts("");
		for(int i=1;i<=n;i++)
			scanf("%d",&num[i]);
		dfs(0,0);
	}
}