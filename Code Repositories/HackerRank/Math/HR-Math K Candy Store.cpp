#include<iostream>
#include<cstring>
#define ll long long
using namespace std;
const ll mod=1e9;
const int maxn=2e3+5;
int pcnt,p[maxn],cnt[maxn];
bool vis[maxn];
ll qpow(ll a,int b)
{
    ll ans=1;
    while(b)
    {
        if(b&1) ans=ans*a%mod;
        a=a*a%mod,b>>=1;
    }
    return ans;
}
void update(int x,int d)
{
    for(int i=1;x>1&&i<=pcnt;i++)
        while(x%p[i]==0)
            cnt[i]+=d,x/=p[i];
}
int main()
{
    for(int i=2;i<maxn;i++)
    {
        if(!vis[i]) p[++pcnt]=i;
        for(int j=1;i*p[j]<maxn;j++)
        {
            vis[i*p[j]]=true;
            if(i%p[j]==0) break;    
        }
    }
    int t,n,k;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        memset(cnt,0,sizeof(cnt));
        for(int i=n+k-1;i>k;i--) update(i,1);
        for(int i=2;i<=n-1;i++) update(i,-1);
        ll ans=1;
        for(int i=1;i<=pcnt;i++) if(cnt[i])
            ans=(ans*qpow(p[i],cnt[i]))%mod;
        cout<<ans<<endl;
    }
}