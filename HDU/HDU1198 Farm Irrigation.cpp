#include<bits/stdc++.h>
using namespace std;
const int maxn=3e3+5;
int n,m,dir[55][55][4],pos[11][4],f[maxn],cnt;
char s[55];
int find(int x)
{	return f[x]==x?x:f[x]=find(f[x]); }
int getid(int i,int j)
{	return m*(i-1)+j; }
void merge(int x1,int y1,int x2,int y2)
{
	int fu=find(getid(x1,y1)),fv=find(getid(x2,y2));
	if(fu!=fv) f[fu]=fv,cnt--;	
}
void init()
{
	pos[0][0]=pos[0][2]=pos[1][0]=pos[1][3]=1;
	pos[2][1]=pos[2][2]=pos[3][1]=pos[3][3]=1;
	pos[4][0]=pos[4][1]=pos[5][2]=pos[5][3]=1;
	pos[6][0]=pos[6][2]=pos[6][3]=pos[7][0]=1;
	pos[7][1]=pos[7][2]=pos[8][1]=pos[8][2]=1;
	pos[8][3]=pos[9][0]=pos[9][1]=pos[9][3]=1;
	pos[10][0]=pos[10][1]=1;
	pos[10][2]=pos[10][3]=1;
}
int main()
{
	init();
	while(scanf("%d%d",&n,&m)&&(n>0||m>0))
	{
		memset(dir,0,sizeof(dir));
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				f[getid(i,j)]=getid(i,j);
		cnt=n*m;
		for(int i=1;i<=n;i++)
		{
			scanf("%s",s+1);
			for(int j=1;j<=m;j++)
			{
				int idx=s[j]-'A';
				if(pos[idx][0]&&i>1&&dir[i-1][j][1]) 
					merge(i,j,i-1,j);
				if(pos[idx][2]&&j>1&&dir[i][j-1][3]) 
					merge(i,j,i,j-1);
				for(int k=0;k<4;k++)
					dir[i][j][k]=pos[idx][k];
			}
		}
		printf("%d\n",cnt);
	}
}