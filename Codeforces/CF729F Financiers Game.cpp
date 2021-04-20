#include<bits/stdc++.h>
using namespace std;
const int maxn=4e3+5,base=70;
int dp[maxn][140][70][2],s[maxn],n;
int query(int l,int r)
{	return s[r]-s[l-1]; }
int dfs(int l,int dif,int k,bool tag)
{
	int r=l+dif-base,ans=0;
	if(l+r+k>n) return 0;
	if(~dp[l][dif][k][tag])
		return dp[l][dif][k][tag];
	if(!tag)
	{
		ans=dfs(l+k,dif-k,k,true)+query(l+1,l+k);
		if(l+r+k+1<=n)
			ans=max(ans,dfs(l+k+1,dif-k-1,k+1,!tag)+query(l+1,l+k+1));
	}
	else
	{
		ans=dfs(l,dif+k,k,false)-query(n-r-k+1,n-r);
		if(l+r+k+1<=n)
			ans=min(ans,dfs(l,dif+k+1,k+1,!tag)-query(n-r-k,n-r));
	}
	return dp[l][dif][k][tag]=ans;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&s[i]),s[i]+=s[i-1];
	memset(dp,-1,sizeof(dp));
	printf("%d\n",dfs(0,base,1,0));
}
