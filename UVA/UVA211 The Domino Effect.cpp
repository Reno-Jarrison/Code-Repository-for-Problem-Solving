#include<bits/stdc++.h>
using namespace std;
int g[10][10],ans[10][10],idx[10][10],cnt;
bool vis[30];
bool read()
{
	int x,r=1,c=0;
	if(scanf("%d",&x)==-1) return false;
	while(r<8)
	{
		g[r][++c]=x;
		if(r==7&&c==8) break;
		scanf("%d",&x);
		if(c==8) r++,c=0;
	}
	return true;
}
void dfs(int r,int c)
{
	while(ans[r][c])
		c==9?(r++,c=1):c++;
	if(r==8)
	{
		puts(""),cnt++;
		for(int i=1;i<=7;i++)
		{
			for(int j=1;j<=8;j++)
				printf("%4d",ans[i][j]);		
			puts("");
		}
		return;
	}
	if(!ans[r][c+1])
	{
		int id=idx[g[r][c]][g[r][c+1]];
		if(!vis[id])
		{
			vis[id]=true,ans[r][c]=ans[r][c+1]=id;
			dfs(r,c+1);
			vis[id]=false,ans[r][c]=ans[r][c+1]=0;
		}
	}
	if(!ans[r+1][c])
	{
		int id=idx[g[r][c]][g[r+1][c]];
		if(!vis[id])
		{
			vis[id]=true,ans[r][c]=ans[r+1][c]=id;
			dfs(r,c+1);
			vis[id]=false,ans[r][c]=ans[r+1][c]=0;
		}
	}
}
int main()
{
//	freopen("Input.txt","r",stdin);
//	freopen("Output.txt","w",stdout);
	int pt=0,ks=0;
	for(int i=0;i<=6;i++)
		for(int j=i;j<=6;j++)
			idx[i][j]=idx[j][i]=++pt;
	for(int i=1;i<=7;i++) ans[i][9]=1;
	for(int i=1;i<=8;i++) ans[8][i]=1;
	while(read())
	{
		if(ks) puts("\n\n");
		printf("Layout #%d:\n\n\n",++ks);
		for(int i=1;i<=7;i++)
		{
			for(int j=1;j<=8;j++)
				printf("%4d",g[i][j]);
			puts("");
		}
		printf("\nMaps resulting from layout #%d are:\n",ks);
		cnt=0,dfs(1,1);
		printf("\nThere are %d solution(s) for layout #%d.\n",cnt,ks);
	}
}