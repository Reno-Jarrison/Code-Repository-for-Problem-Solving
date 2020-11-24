#include<iostream>
#include<cstring>
#define ll long long
using namespace std;
const int maxn=5e4+5;
const ll mod=1e9+7;
int cnt[maxn];
int main()
{
    int t,n,c;
    cin>>t;
    while(t--)
    {
        memset(cnt,0,sizeof(cnt));
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>c,cnt[c]++;
        ll ans=1;
        for(int i=1;i<=n;i++)
            cnt[i]+=cnt[i-1];
        for(int i=0;i<n;i++)
            ans=ans*(cnt[i]-i)%mod;
        cout<<ans<<endl;
    }
}