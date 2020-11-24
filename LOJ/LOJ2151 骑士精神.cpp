#include<bits/stdc++.h>
using namespace std;
int dx[8]={-2,-2,-1,-1,1,1,2,2},dy[8]={-1,1,-2,2,-2,2,-1,1};
char s[6][6],res[6][6]={"11111","01111","00211","00001","00000"};
int count()
{
	int cnt[3]={0};
	for(int i=0;i<5;i++)
		for(int j=0;j<5;j++)
			cnt[res[i][j]-'0']+=(s[i][j]==res[i][j]);
	return 24-(cnt[0]+cnt[1]);
}
bool dfs(int d,int ux,int uy,int lim)
{
	if(d+count()>lim) return false;
	if(!count()) return true;
	for(int i=0;i<8;i++)
	{
		int vx=ux+dx[i],vy=uy+dy[i];
		if(vx<0||vy<0||vx>5||vy>5) continue;
		swap(s[ux][uy],s[vx][vy]);
		if(dfs(d+1,vx,vy,lim)) return true;
		swap(s[ux][uy],s[vx][vy]);
	}
	return false;
}
int main()
{
	int t,sx,sy;
	scanf("%d",&t);
	while(t--)
	{
		for(int i=0;i<5;i++)
		{
			scanf("%s",s[i]);
			for(int j=0;j<5;j++)
				if(s[i][j]=='*') sx=i,sy=j;
		}
		int dep=0;
		while(dep<=15)
		{	if(dfs(0,sx,sy,dep)) break; dep++; }
		printf("%d\n",dep<=15?dep:-1);
	}
}