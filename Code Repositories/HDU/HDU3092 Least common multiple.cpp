#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn=3e3+5;
int ans[maxn],pcnt,vis[maxn],p[maxn];
double dp[maxn];
int main()
{
    for(int i=2;i<maxn-5;i++)
    {
        if(!vis[i]) p[++pcnt]=i;
        for(int j=1;i*p[j]<maxn-5;j++)
        {
            vis[i*p[j]]=true;
            if(i%p[j]==0) break;
        }
    }
    int s,m;
    while(cin>>s>>m)
    {
        for(int i=0;i<=s;i++) 
            dp[i]=0,ans[i]=1;
        for(int i=1;i<=pcnt&&p[i]<=s;i++)
            for(int j=s;j>=p[i];j--)
                for(int k=p[i];k<=j;k*=p[i])
                    if(dp[j]<dp[j-k]+log(k))
                    {
                        dp[j]=dp[j-k]+log(k);
                        ans[j]=1LL*ans[j-k]*k%m;
                    }
        cout<<ans[s]<<endl;
    }
}