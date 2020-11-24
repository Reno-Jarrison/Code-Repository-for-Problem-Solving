#include<bits/stdc++.h>
#define ll long long
using namespace std;
int dp[35][25],num[35],k,b;
int dfs(int pos,int cnt,bool limit)
{
	if(!pos||cnt>k) return cnt==k;
	if(!limit&&dp[pos][cnt]!=-1) return dp[pos][cnt];
	int bound=limit?num[pos]:1,ans=0; 
	for(int i=0;i<=bound;i++)
		ans+=dfs(pos-1,cnt+i,limit&&i==num[pos]);
	if(!limit) dp[pos][cnt]=ans;
	return ans;
}
int query(int x)
{
	int len=0;
	bool flag=false;
	while(x) num[++len]=x%b,x/=b;
	for(int i=len;i;i--)
		if(flag) num[i]=1;
		else if(num[i]>1) num[i]=1,flag=true;
	return dfs(len,0,true);
}
int main()
{
	int x,y;
	cin>>x>>y>>k>>b;
	memset(dp,-1,sizeof(dp));
	cout<<query(y)-query(x-1);
}