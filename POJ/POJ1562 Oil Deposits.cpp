#include<iostream>
#include<cstring>
using namespace std;
char sig[105][105];
int counts,m,n,set,flag[105][105];
int xn[8]={1,1,1,0,0,-1,-1,-1};
int yn[8]={0,-1,1,1,-1,-1,0,1};
void dfs(int x,int y)
{
	
	if(x<0||y<0||x>=m||y>=n)
		return;
	if(sig[x][y]=='@')
	{
		if(!flag[x][y])
		{
			if(!set)
				counts++,set=1;
			flag[x][y]=counts;
			for(int i=0;i<8;i++)
				dfs(x+xn[i],y+yn[i]);
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	while(cin>>m>>n&&m)
	{
		memset(flag,0,sizeof(flag));
		for(int i=0;i<m;i++)	
			for(int j=0;j<n;j++)	
				cin>>sig[i][j];
		for(int i=0;i<m;i++)	
			for(int j=0;j<n;j++)	
				set=0,dfs(i,j);
		cout<<counts<<endl;
		counts=0;
	}
 } 