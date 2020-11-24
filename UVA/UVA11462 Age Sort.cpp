#include<bits/stdc++.h>
using namespace std;
int vis[100];
int main()
{
	int n,x,fst;
	while(scanf("%d",&n)&&n)
	{
		memset(vis,0,sizeof(vis)),fst=1;
		while(n--)
			scanf("%d",&x),vis[x]++;
		for(int i=0;i<100;i++)
			while(vis[i]--) 
			{
				if(fst) fst=0;
				else putchar(' ');
				printf("%d",i);
			}
		puts("");
	}
}