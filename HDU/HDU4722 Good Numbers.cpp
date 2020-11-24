#include<cstdio>
#include<cstring>
#define ll long long
using namespace std;
int num[65];
ll dp[65][10];
ll dfs(int pos,int sum,bool lim)
{
    if(!pos) return !sum;
    if(!lim&&dp[pos][sum]!=-1) return dp[pos][sum];
    ll ans=0;
    int upb=lim?num[pos]:9;
    for(int i=0;i<=upb;i++)
        ans+=dfs(pos-1,(sum+i)%10,lim&&i==num[pos]);
    if(!lim) dp[pos][sum]=ans;
    return ans;
}
ll query(ll x)
{
    if(x<0) return 0;
    int cnt=0;
    while(x) num[++cnt]=x%10,x/=10;
    return dfs(cnt,0,true);
}
int main()
{
    int t,cases=0;
    ll a,b,ans;
    scanf("%d",&t);
    memset(dp,-1,sizeof(dp));
    while(t--)
    {
        scanf("%lld%lld",&a,&b);
        ans=query(b)-query(a-1);
        printf("Case #%d: %lld\n",++cases,ans);
    }
}