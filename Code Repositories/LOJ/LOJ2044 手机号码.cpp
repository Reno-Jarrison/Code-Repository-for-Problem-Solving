#include<cstdio>
#include<cstring>
#include<iostream>
#define ll long long
using namespace std;
ll dp[20][20][10][2][2][2],num[20];
ll dfs(int pos,int cnt,int pre,bool ok,bool flag4,bool flag8,bool limit,bool lead)
{
	if(!pos) return !(flag4&&flag8)&&ok;
	if(!limit&&!lead&&dp[pos][cnt][pre][ok][flag4][flag8]!=-1) 
		return dp[pos][cnt][pre][ok][flag4][flag8];
	int bound=limit?num[pos]:9;
	ll ans=0;
	for(int i=lead?1:0;i<=bound;i++)
	{
		if((i==4&&flag8)||(i==8&&flag4)) continue;
		int tmp=(i==pre?cnt+1:1);
		ans+=dfs(pos-1,tmp,i,ok||(tmp>=3),flag4||i==4,flag8||i==8,limit&&i==bound,false);
	}
	if(!limit&&!lead) dp[pos][cnt][pre][ok][flag4][flag8]=ans;
	return ans;
}
ll query(ll x)
{
	int len=0;
	while(x) num[++len]=x%10,x/=10;
	if(len<=10) return 0;
	return dfs(len,0,0,false,false,false,true,true); 
}
int main()
{
	ll a,b;
	memset(dp,-1,sizeof(dp));
	scanf("%lld%lld",&a,&b);
	printf("%lld",query(b)-query(a-1));
}