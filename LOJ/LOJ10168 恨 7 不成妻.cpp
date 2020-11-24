#include<cstdio>
#include<cstring>
#define ll long long
#include<iostream>
using namespace std;
const ll mod=1e9+7;
struct node
{
	ll cnt,sum,sqm;
	node(ll a=-1,ll b=0,ll c=0):cnt(a),sum(b),sqm(c){}
}dp[20][10][10];
ll num[20],pow10[20];
ll sqr(ll x) { return x*x%mod; }
node dfs(int pos,int sum1,int sum2,bool limit)
{
	if(!pos) return node((sum1%7)&&(sum2%7),0,0);
	if(!limit&&dp[pos][sum1][sum2].cnt!=-1) return dp[pos][sum1][sum2];
	int bound=limit?num[pos]:9;
	node ans(0,0,0);
	for(int i=0;i<=bound;i++)
	{
		if(i==7) continue;
		node tmp=dfs(pos-1,(sum1*10+i)%7,(sum2+i)%7,limit&&i==bound);
		(ans.cnt+=tmp.cnt)%=mod;
		(ans.sum+=tmp.cnt*pow10[pos-1]%mod*i%mod+tmp.sum)%=mod;
		(ans.sqm+=sqr(pow10[pos-1]*i%mod)*tmp.cnt%mod+2LL*i*pow10[pos-1]%mod*tmp.sum%mod+tmp.sqm)%=mod;
	}
	if(!limit) dp[pos][sum1][sum2]=ans;
	return ans;
}
ll query(ll x)
{
	int len=0;
	while(x) num[++len]=x%10,x/=10;
	return dfs(len,0,0,true).sqm;
}
void getpow()
{
	pow10[0]=1;
	for(int i=1;i<=20;i++)
		pow10[i]=pow10[i-1]*10%mod;
}
int main()
{
	int t;
	ll l,r;
	scanf("%d",&t);
	getpow();
	while(t--)
	{
		scanf("%lld%lld",&l,&r);
		printf("%lld\n",(query(r)-query(l-1)+mod)%mod);
	}
} 