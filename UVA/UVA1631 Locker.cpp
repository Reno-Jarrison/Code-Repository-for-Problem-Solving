#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+5;
int dp[maxn][10][10][10],s[maxn],t[maxn],n;
char src[maxn],dst[maxn];
int dfs(int step,int x,int y,int z)
{
	if(step>n) return 0;
	int &val=dp[step][x][y][z];
	if(val!=-1) return val;
	val=0x3f3f3f3f;
	int inc=(t[step]-x+10)%10,dec=(x-t[step]+10)%10;
	for(int i=0;i<=inc;i++)
		for(int j=0;j<=i;j++)
			val=min(val,dfs(step+1,(y+i)%10,(z+j)%10,s[step+3])+inc);
	for(int i=0;i<=dec;i++)
		for(int j=0;j<=i;j++)
			val=min(val,dfs(step+1,(y-i+10)%10,(z-j+10)%10,s[step+3])+dec);
	return val;
}
int main()
{
	while(~scanf("%s%s",src+1,dst+1))
	{
		n=strlen(src+1);
		for(int i=1;i<=n;i++)
			s[i]=src[i]-'0',t[i]=dst[i]-'0';
		s[n+1]=s[n+2]=t[n+1]=t[n+2]=0;
		memset(dp,-1,sizeof(dp));
		printf("%d\n",dfs(1,s[1],s[2],s[3]));
	}
}