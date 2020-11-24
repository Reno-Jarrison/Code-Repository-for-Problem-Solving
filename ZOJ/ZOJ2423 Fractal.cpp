#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+5;
int pow3[8],tag[maxn][maxn];
void dfs(int x,int y,int len)
{
	if(len==0) return void(tag[x][y]=1);
	int d=pow3[len-1];
	dfs(x,y,len-1);
	dfs(x+2*d,y,len-1);
	dfs(x+2*d,y,len-1);
	dfs(x+d,y+d,len-1);
	dfs(x,y+2*d,len-1);
	dfs(x+2*d,y+2*d,len-1);
}
void init(int n)
{
	pow3[0]=1;
	for(int i=1;i<=n;i++)
		pow3[i]=pow3[i-1]*3;
	dfs(1,1,n);
}
int main()
{
	init(6);
	int n;
	while(scanf("%d",&n)&&n!=-1)
	{
		for(int i=1;i<=pow3[n-1];i++)
		{
			int mxr=pow3[n-1];
			while(!tag[i][mxr]) mxr--;
			for(int j=1;j<=mxr;j++)
				putchar(tag[i][j]?'X':' ');
			puts("");
		}
		puts("-");
	}
}