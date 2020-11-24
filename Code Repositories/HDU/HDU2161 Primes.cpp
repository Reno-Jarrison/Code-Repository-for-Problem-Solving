#include<bits/stdc++.h>
#define maxn 16005
using namespace std;
int cnt,p[maxn],vis[maxn+5];
int main()
{
	int cases=0,n;
	for(int i=2;i<=maxn;i++)
	{
		if(!vis[i]) p[++cnt]=i;
		for(int j=1;i*p[j]<=maxn;j++)
		{
			vis[i*p[j]]=true;
			if(i%p[j]==0) break;
		}
	}
	vis[1]=vis[2]=1;
	while(scanf("%d",&n)&&n>0)
		printf("%d: %s",++cases,vis[n]?"no\n":"yes\n");
}
