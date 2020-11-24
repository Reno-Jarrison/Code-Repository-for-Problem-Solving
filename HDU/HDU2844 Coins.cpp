#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1e5+5;
int w[maxn],num[maxn],dp[maxn],pow2[15]={1};
void pack(int x,int m)
{    for(int i=m;i>=x;i--) dp[i]|=dp[i-x]; }
int main()
{
    int n,m;
    for(int i=1;i<15;i++) pow2[i]=pow2[i-1]<<1;
    while(cin>>n>>m&&n)
    {
        for(int i=1;i<=n;i++) cin>>w[i];
        for(int i=1;i<=n;i++) cin>>num[i];
        memset(dp,0,sizeof(dp)),dp[0]=1;
        for(int i=1,pt=0;i<=n;i++,pt=0) while(true)
        {
            if(num[i]>=pow2[pt+1]-1) pack(pow2[pt++]*w[i],m);
            else { pack((pow2[pt]-pow2[pt+1]+num[i]+1)*w[i],m); break; }
        }
        int ans=0;
        for(int i=1;i<=m;i++) ans+=dp[i];
        cout<<ans<<endl;
    }
}