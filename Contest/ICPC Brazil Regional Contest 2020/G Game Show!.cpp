#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,v,ans=100,sum=100;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&v),sum+=v,ans=max(ans,sum);
	printf("%d\n",ans);
}