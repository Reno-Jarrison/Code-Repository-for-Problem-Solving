#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=45;
ll dp[maxn]={0,1};
int main()
{
    for(int i=2;i<maxn;i++)
        dp[i]=dp[i-1]+dp[i-2];
    int t,n;
    cin>>t;
    while(t--)
        cin>>n,cout<<dp[n]<<endl;
}