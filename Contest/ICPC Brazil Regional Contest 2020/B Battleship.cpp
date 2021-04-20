#include<bits/stdc++.h>
using namespace std;
bool tag[15][15];
int main()
{
	int n,d,l,r,c,ok=1;
	scanf("%d",&n);
	for(int i=1;i<=n&&ok;i++)
	{
		scanf("%d%d%d%d",&d,&l,&r,&c);
		for(int j=0;j<l&&ok;j++)
		{
			int x=r+(d?j:0),y=c+(d?0:j);
			if(x<1||y<1||x>10||y>10) ok=0;
			if(tag[x][y]) ok=0;
			tag[x][y]=true;
		}
	}
	puts(ok?"Y":"N");
}