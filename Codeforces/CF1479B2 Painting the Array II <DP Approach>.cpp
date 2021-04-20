#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int a[maxn],pos[maxn],pre[maxn],dp[maxn];
int getval(int j,int i)
{	return dp[j]+i-j-1+!(a[j-1]==a[i]); }
int main()
{
	int n,x,las=0,tot=0,ans;
	scanf("%d",&n),ans=n;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		if(x!=las) a[++tot]=x,las=x;
	}
	for(int i=1;i<=tot;i++)
		pre[i]=pos[a[i]],pos[a[i]]=i;
	dp[1]=1;
	for(int i=2;i<=tot;i++)
	{
		dp[i]=min(getval(i-1,i),getval(pre[i]+1,i));
		ans=min(ans,dp[i]+tot-i);
	}
	printf("%d\n",ans);
}