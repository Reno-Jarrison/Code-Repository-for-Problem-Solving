#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int cnt,p[maxn],vis[maxn];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=2;i<=n+1;i++)
	{
		if(!vis[i]) p[++cnt]=i;
		for(int j=1;j<=cnt&&p[j]*i<=n+1;j++)
		{
			vis[p[j]*i]=1;
			if(i%p[j]==0) break;
		}
	}
	printf("%d\n",1+(n>2));
	for(int i=2;i<=n+1;i++) printf("%d ",1+vis[i]);
}
