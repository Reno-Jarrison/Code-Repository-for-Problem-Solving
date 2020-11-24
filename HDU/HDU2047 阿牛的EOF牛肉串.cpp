#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=55;
ll dp[maxn]={1,3};
int main()
{
    for(int i=2;i<40;i++)
        dp[i]=(dp[i-1]+dp[i-2])<<1;
    int x;
    while(~scanf("%d",&x))
        printf("%lld\n",dp[x]);
}