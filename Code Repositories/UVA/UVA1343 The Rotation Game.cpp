#include<bits/stdc++.h>
using namespace std;
int g[24],cnt[4],id;
int opt[8][7]={{0,2,6,11,15,20,22},{1,3,8,12,17,21,23},
			   {10,9,8,7,6,5,4},{19,18,17,16,15,14,13},
			   {23,21,17,12,8,3,1},{22,20,15,11,6,2,0},
			   {13,14,15,16,17,18,19},{4,5,6,7,8,9,10}};
int res[8]={6,7,8,11,12,15,16,17},rev[8]={5,4,7,6,1,0,3,2};
char ans[100000];
bool read()
{
	for(int i=0;i<24;i++)
	{
		scanf("%d",&g[i]);
		if(!g[i]) return false;
	}
	return true;
}
int count()
{
	cnt[1]=cnt[2]=cnt[3]=0;
	for(int i=0;i<8;i++)
		cnt[g[res[i]]]++;
	return 8-max(cnt[1],max(cnt[2],cnt[3]));
}
void update(int dir)
{
	int tmp=g[opt[dir][0]];
	for(int i=0;i<6;i++)
			g[opt[dir][i]]=g[opt[dir][i+1]];
		g[opt[dir][6]]=tmp;
}
bool dfs(int step,int lim)
{
	int h=count();
	if(step+h>lim) return false;
	if(!h) 
	{	id=g[res[0]],ans[step]=0; return true; }
	for(int i=0;i<8;i++)
	{
		update(i);
		ans[step]='A'+i;
		if(dfs(step+1,lim)) return true;
		update(rev[i]);
	}
	return false;
}
int main()
{
	while(read())
	{
		int dep=0;
		if(!count())
		{	printf("No moves needed\n%d\n",g[res[0]]); continue; }
		while(true)
		{	if(dfs(0,dep)) break; dep++; }
		printf("%s\n%d\n",ans,id);
	}
}