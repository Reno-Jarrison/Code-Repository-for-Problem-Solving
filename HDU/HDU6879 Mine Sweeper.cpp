#include<bits/stdc++.h>
using namespace std;
int vis[26][26];
int main()
{
	int t,s;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&s);
		if(s<=24)
		{
			printf("%d %d\n",1,s+1);
			for(int i=1;i<=s+1;i++)
				printf("%c",i&1?'X':'.');
			puts("");
		}
		else
		{
			memset(vis,0,sizeof(vis));
			int num=s/8,q=num/12,r=num%12,res=s%8;
			for(int i=1;i<=q;i++)
				for(int j=1;j<=12;j++)
					vis[i*2][j*2]=1;
			for(int i=1;i<=r;i++)
				vis[(q+1)*2][i*2]=1;
			if(q) for(int i=1;i<=res;i++) 
				vis[1][i*2-1]=1;
			else
			{
				for(int i=1;i<=min(4,res);i++)
					vis[1][i*2-1]=1;
				for(int i=1;i<=res-4;i++)
					vis[3][i*2-1]=1;
			}
			int R=(q+(r>0))*2+1,C=q?25:max(r*2+1,min(4,res)*2-1);
			printf("%d %d\n",R,C);
			for(int i=1;i<=R;i++)
			{
				for(int j=1;j<=C;j++)
					printf("%c",vis[i][j]?'X':'.');
				puts("");
			}
		}
	}
}