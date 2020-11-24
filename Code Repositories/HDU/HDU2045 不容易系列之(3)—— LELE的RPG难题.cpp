#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=55;
ll dp[maxn]={0,3,6,6};
int main()
{
    for(int i=4;i<=50;i++)
        dp[i]=dp[i-1]+2*dp[i-2];
    int x;
    while(~scanf("%d",&x))
        printf("%lld\n",dp[x]);
}