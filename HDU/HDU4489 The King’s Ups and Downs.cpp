#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=25;
ll dp[maxn]={1,1},c[maxn][maxn],ans[maxn]={0,1};
int main()
{
    int t,id,n;
    cin>>t;
    for(int i=1;i<=20;i++)
    {
        c[i][0]=c[i][i]=1;
        for(int j=1;j<i;j++)
            c[i][j]=c[i-1][j]+c[i-1][j-1];
    }
    for(int i=2;i<=20;i++)
        for(int j=0;j<i;j++)
            ans[i]+=dp[j]*dp[i-j-1]*c[i-1][j],dp[i]=ans[i]/2;
    while(t--)
        cin>>id>>n,cout<<id<<" "<<ans[n]<<endl;
}