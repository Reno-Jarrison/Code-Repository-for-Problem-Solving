#include<bits/stdc++.h>
using namespace std;
const int maxn=105;
int p[maxn];
int main()
{
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&p[i]);
		for(int i=n;i;i--)
			printf("%d ",p[i]);
		puts("");
	}
}