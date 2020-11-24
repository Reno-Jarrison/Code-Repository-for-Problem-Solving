#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod=1e9+7;
struct node
{
    ll cnt,sum,sqr;
    node(ll cnt=0,ll sum=0,ll sqr=0):cnt(cnt),sum(sum),sqr(sqr){}
}dp[20][7][7];
ll pow10[20];
int num[20],vis[20][7][7];
node dfs(int pos,int s1,int s2,bool lim)
{
    if(!pos) return node(s1&&s2,0,0);
    if(!lim&&vis[pos][s1][s2]) return dp[pos][s1][s2];
    int bound=lim?num[pos]:9;
    node ans;
    for(int i=0;i<=bound;i++)
    {
        if(i==7) continue;
        node nxt=dfs(pos-1,(s1+i)%7,(s2*10+i)%7,lim&&i==bound);
        ll bit=pow10[pos]*i%mod;
        ans.cnt=(ans.cnt+nxt.cnt)%mod;
        ans.sum=(ans.sum+nxt.sum+bit*nxt.cnt%mod)%mod;
        ans.sqr=(ans.sqr+bit*bit%mod*nxt.cnt%mod+2LL*bit*nxt.sum%mod+nxt.sqr%mod)%mod;
    }
    if(!lim) vis[pos][s1][s2]=1,dp[pos][s1][s2]=ans;
    return ans;
}
ll query(ll x)
{
    int len=0;
    while(x) num[++len]=x%10,x/=10;
    return dfs(len,0,0,true).sqr;
}
int main()
{
    int t;
    scanf("%d",&t);
    pow10[1]=1;
    for(int i=2;i<20;i++)
        pow10[i]=10LL*pow10[i-1]%mod;
    while(t--)
    {
        ll l,r;
        scanf("%lld%lld",&l,&r);
        printf("%lld\n",(query(r)-query(l-1)+mod)%mod);
    }
}