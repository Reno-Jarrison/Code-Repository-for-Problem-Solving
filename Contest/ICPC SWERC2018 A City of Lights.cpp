#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
int tag[maxn];
int main()
{
	int n,k,x,cur=0,ans=0;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&x);
		for(int j=1;j*x<=n;j++)
			tag[j*x]^=1,tag[j*x]?cur++:cur--;
		ans=max(ans,cur);
	}
	printf("%d",ans);
}