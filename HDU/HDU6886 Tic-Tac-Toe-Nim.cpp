#include<bits/stdc++.h>
using namespace std;
int a[4][4];
bool dfs(int x,int y,int sum)
{
	for(int i=1;i<=3;i++)
		for(int j=1;j<=3;j++)
		{
			if(i==x||j==y) continue;
			if(((a[x][y]-1)^(a[i][j]-1)^a[6-x-i][6-y-j]^
				(a[6-x-i][6-y-j]-1))==sum) return false;
		}
	return true;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int ans=0,sum=0;
		for(int i=1;i<=3;i++)
			for(int j=1;j<=3;j++)
				scanf("%d",&a[i][j]),sum^=(a[i][j]-1);
		for(int i=1;i<=3;i++)
			for(int j=1;j<=3;j++)
				if(dfs(i,j,sum)) ans++;
		printf("%d\n",ans);
	}
}