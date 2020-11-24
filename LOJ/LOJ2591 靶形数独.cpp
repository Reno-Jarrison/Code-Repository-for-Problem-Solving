#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int map[10][10],cnt,ans;
bool visr[10][10],visc[10][10],visq[10][10],flag,none;
struct node
{
	int id,counter;
	bool operator <(const node &x) const
		{ return counter>x.counter; }
}row[10],col[10];
struct Point
{
	int x,y;
}p[90];
inline int score(int x,int y)
	{ return 10-max(abs(x-4),abs(y-4)); }
void dfs(int step,int sum)
{
	int x=p[step].x,y=p[step].y;
	if(step==81) ans=max(ans,sum),flag=1;
	for(int i=1;i<=9;i++)
	{
		if(visr[x][i]||visc[y][i]||visq[x/3+y/3*3][i]) continue;
		visr[x][i]=visc[y][i]=visq[x/3+y/3*3][i]=1;
		map[x][y]=i,cnt++;
		dfs(step+1,sum+score(x,y)*i);
		map[x][y]=0,cnt--;
		visr[x][i]=visc[y][i]=visq[x/3+y/3*3][i]=0;
	}
}
int main()
{
	for(int i=0;i<9;i++)
		row[i].id=col[i].id=i;
	for(int i=0;i<9;i++)
		for(int j=0;j<9;j++)
		{
			scanf("%d",&map[i][j]);
			if(map[i][j]) 
			{
				int val=map[i][j];
				if(visr[i][val]||visc[j][val]||visq[i/3+j/3*3][val]) none=1;
				visr[i][val]=1;
				visc[j][val]=1;
				visq[i/3+j/3*3][val]=1;
				cnt++;
				ans+=val*score(i,j);
				row[i].counter++;
				col[j].counter++;
			}
		}
	sort(row,row+9);
	sort(col,col+9);
	int temp=cnt;
	for(int i=0;i<9;i++)
		for(int j=0;j<9;j++)
			if(!map[row[i].id][col[j].id])
				p[temp++]={row[i].id,col[j].id};
	if(!none) dfs(cnt,ans);
	if(!flag) ans=-1;
	printf("%d",ans);
}