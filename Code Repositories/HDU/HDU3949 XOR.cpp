#include<cstdio>
#include<cstring>
#define ll long long
using namespace std;
struct libasis
{
    bool flag;
    ll bas[65];
    libasis(){ flag=false,memset(bas,0,sizeof(bas)); }
    bool insert(ll x)
    {
        for(int i=62;i>=0;i--)
            if(x&(1LL<<i))
            {
                if(bas[i]) x^=bas[i];
                else { bas[i]=x; return true; }
            }
        flag=true;
        return false;
    }
    ll getkth(ll k)
    {
        if(flag) k--;
        if(!k) return 0;
        ll tmp[62],cnt=0,ans=0;
        for(int i=1;i<=62;i++)
        {
            if(bas[i]) for(int j=i-1;j>=0;j--)
                if(bas[i]&(1LL<<j))
                    bas[i]^=bas[j];
        }
        for(int i=0;i<=62;i++)
            if(bas[i]) tmp[cnt++]=bas[i];
        if(k>=(1LL<<cnt)) return -1;
        for(int i=0;i<cnt;i++)
            if(k&(1LL<<i)) ans^=tmp[i];        
        return ans;
    }
};
int main()
{
    int t,n,q,cases=0;
    ll x;
    scanf("%d",&t);
    while(t--)
    {
        libasis lb;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%lld",&x),lb.insert(x);
        printf("Case #%d:\n",++cases);
        scanf("%d",&q);
        for(int i=1;i<=q;i++)
            scanf("%lld",&x),printf("%lld\n",lb.getkth(x));
    }
}