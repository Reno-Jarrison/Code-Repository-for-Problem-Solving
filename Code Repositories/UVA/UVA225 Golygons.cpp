#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=2e3+5,delt=1e3;
int flag[maxn][maxn];
int cnt,ans[25],ch[4]={'e','n','s','w'},rev[4]={3,2,1,0};
int nx[4]={1,0,0,-1},ny[4]={0,1,-1,0};
void dfs(int x,int y,int dir,int step,int end)
{
	if(step==end+1)
	{
		if(x||y) return;
		for(int i=1;i<step;i++)
			printf("%c",ch[ans[i]]);
		cnt++,puts("");
	}
	if((step+end)*(end-step+1)/2<abs(x)+abs(y)) return;
	for(int i=0;i<4;i++)
	{
		if(dir==i||dir==rev[i]) continue;
		int xx=x,yy=y,ok=1;
		for(int j=1;j<=step;j++)
		{
			xx+=nx[i],yy+=ny[i];
			if(flag[xx+delt][yy+delt]==1) ok=false;
		}
		if(flag[xx+delt][yy+delt]==2) ok=0;
		if(ok)
		{
			flag[xx+delt][yy+delt]=2;
			ans[step]=i,dfs(xx,yy,i,step+1,end);
			flag[xx+delt][yy+delt]=0;
		}
	}
}
int main()
{
	int t,n,k,kx,ky;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		memset(flag,0,sizeof(flag));
		for(int i=0;i<k;i++)
		{
			scanf("%d%d",&kx,&ky);
			flag[kx+delt][ky+delt]=1;
		}
		cnt=0,dfs(0,0,-1,1,n);	
		printf("Found %d golygon(s).\n\n",cnt);
	}
}