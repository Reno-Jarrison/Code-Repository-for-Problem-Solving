#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+5;
int num[maxn],ans[maxn][maxn],vis[maxn][maxn],d;
int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
void solve(int x,int y,int step,int r,int c)
{
	if(!step) return;
	ans[x][y]=num[step],vis[x][y]=1;
	int nx=x+dx[d],ny=y+dy[d];
	if(nx<1||nx>r||ny<1||ny>c||vis[nx][ny])
		d=(d+1)%4;
	nx=x+dx[d],ny=y+dy[d];
	solve(nx,ny,step-1,r,c);
}
int main()
{
	int n,r,c;
	scanf("%d",&n),r=n,c=1;
	for(int i=1;i<=n;i++)
		scanf("%d",&num[i]);
	sort(num+1,num+n+1);
	for(int i=2;i*i<=n;i++)
		if(n%i==0) c=i,r=n/i;
	solve(1,1,n,r,c);
	for(int i=1;i<=r;i++)
		for(int j=1;j<=c;j++)
			printf("%d%c",ans[i][j],j==c?'\n':' ');
}