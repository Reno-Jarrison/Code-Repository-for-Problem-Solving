#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1e4+5;
const double inf=1e12;
double dp[maxn];
int main()
{
    int t,n,w;
    double p,c;
    cin>>t;
    while(t--)
    {
        cin>>p>>n;
        int ans=0,s=0;
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        for(int i=1;i<=n;i++)
        {
            cin>>w>>c,s+=w;
            for(int j=s;j>=w;j--)
                dp[j]=max(dp[j],dp[j-w]*(1-c));
        }
        for(int i=1;i<=s;i++)
            if(dp[i]>1-p) ans=i;
        cout<<ans<<endl;
    }
}