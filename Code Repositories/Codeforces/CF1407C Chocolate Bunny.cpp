#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+5;
int ans[maxn],vis[maxn];
int main()
{
	int n,a,b,las=1;
	scanf("%d",&n);
	for(int i=2;i<=n;i++)
	{
		printf("? %d %d\n",i,las);
		fflush(stdout);
		scanf("%d",&a);	
		printf("? %d %d\n",las,i);	
		fflush(stdout);	
		scanf("%d",&b);
		if(a>b) ans[i]=a,vis[a]=1;
		else ans[las]=b,vis[b]=1,las=i;
	}
	for(int i=1;i<=n;i++)
		if(!vis[i]) ans[las]=i;
	printf("!");
	for(int i=1;i<=n;i++)
		printf(" %d",ans[i]);
	fflush(stdout);
}