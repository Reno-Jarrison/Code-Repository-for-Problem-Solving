#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5,inf=0x3f3f3f3f;
int col[maxn],l[maxn],r[maxn],bkt[maxn],dp[maxn];
int main()
{
	int n;
	scanf("%d",&n);
	memset(l,inf,sizeof(l));
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&col[i]);
		l[col[i]]=min(l[col[i]],i);
		r[col[i]]=max(r[col[i]],i);
	}
	for(int i=n;i;i--)
	{
		int x=col[i];
		dp[i]=max(dp[i+1],++bkt[x]+(i==l[x]?dp[r[x]+1]:0));
	}
	printf("%d\n",n-dp[1]);
}