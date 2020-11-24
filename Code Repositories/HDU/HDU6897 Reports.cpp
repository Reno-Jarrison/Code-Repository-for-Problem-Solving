#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		int cur,las=-1,ok=1;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&cur);
			if(cur==las) ok=0;
			las=cur;
		}
		puts(ok?"YES":"NO");
	}
}