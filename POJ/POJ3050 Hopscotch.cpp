#include<iostream>
#include<cstdio>
using namespace std;
int p[5][5],temp[6],nx[4]={1,-1,0,0},ny[4]={0,0,1,-1};
int sum=1; 
bool flag[1000000];
void dfs(int x,int y,int step)
{
	if(x<0||y<0||x>4||y>4)
		return;
	temp[step]=p[x][y];
	if(step==6)
	{
		int temp0=0;
		for(int i=0,x=1;i<6;i++)
			temp0+=temp[i]*x,x*=10;
		if(!flag[temp0])
			flag[temp0]=1,sum++;
		return;
	}
	for(int i=0;i<4;i++)
		dfs(x+nx[i],y+ny[i],step+1);
}
int main()
{
	for(int i=0;i<5;i++)
		for(int j=0;j<5;j++)
			cin>>p[i][j];
	for(int i=0;i<5;i++)
		for(int j=0;j<5;j++)
			dfs(i,j,0);
	cout<<sum-1;			
}