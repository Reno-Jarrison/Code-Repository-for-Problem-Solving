#include<bits/stdc++.h>
using namespace std;
const int maxn=5e3+5;
int vis[maxn];
int main()
{
	int t,n,m,x;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		int pre=0,ok=0;
		fill(vis,vis+m,0);
		vis[0]=1;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&x);
			pre=(pre+x)%m;
			if(vis[pre]) ok=1;
			vis[pre]=1;
		}
		puts(ok?"YES":"NO");
	}
}