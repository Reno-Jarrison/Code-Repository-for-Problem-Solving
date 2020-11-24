#include<bits/stdc++.h>
#define ll long long
#define maxn 50005
using namespace std;
int cnt,len,vis[maxn]={1,1};
ll s,p[maxn],ans[maxn<<1];
bool isprime(ll x)
{
	if(x<=maxn-5) return !vis[x];
	for(int i=1;p[i]*p[i]<=x;i++)
		if(x%p[i]==0) return false;
	return true; 
}
void dfs(int step,ll tmp,ll mul)
{
	if(mul==1) { ans[++len]=tmp; return; }
	else if(mul-1>=p[step]&&isprime(mul-1)) 
		ans[++len]=tmp*(mul-1);
	for(int i=step;p[i]*p[i]<=mul;i++)
	{
		ll tmul=p[i],tsum=tmul+1;
		while(mul>=tsum)
		{
			if(mul%tsum==0)
				dfs(i+1,tmp*tmul,mul/tsum);
			tmul*=p[i],tsum+=tmul;
		}
	}
}
int main()
{
	for(int i=2;i<=maxn-5;i++)
	{
		if(!vis[i]) p[++cnt]=i;
		for(int j=1;i*p[j]<=maxn-5;j++)
		{
			vis[i*p[j]]=1;
			if(i%p[j]==0) break;
		}
	}
	while(scanf("%lld",&s)!=EOF)
	{
		memset(ans,0,sizeof(ans));
		len=0;
		dfs(1,1,s);
		printf("%d\n",len);
		sort(ans+1,ans+len+1);
		for(int i=1;i<=len;i++) 
			printf("%d%c",ans[i],i==len?'\n':' ');
	}
}