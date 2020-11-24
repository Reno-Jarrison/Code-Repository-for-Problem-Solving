#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=60;
ll dp[maxn]={0,1,2,3};
int main()
{
    int n;
    for(int i=4;i<maxn;i++)
        dp[i]=dp[i-1]+dp[i-3];
    while(scanf("%d",&n)&&n)
        printf("%lld\n",dp[n]);    
}