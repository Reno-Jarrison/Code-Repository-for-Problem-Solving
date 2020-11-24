#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1e3+5;
int c[maxn],w[maxn],dp[maxn];
int main()
{
    int t,n,v;
    cin>>t;
    while(t--)
    {
        cin>>n>>v;
        for(int i=1;i<=n;i++) cin>>w[i];
        for(int i=1;i<=n;i++) cin>>c[i];
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++)
            for(int j=v;j>=c[i];j--)
                dp[j]=max(dp[j],dp[j-c[i]]+w[i]);
        cout<<dp[v]<<endl;
    }
}