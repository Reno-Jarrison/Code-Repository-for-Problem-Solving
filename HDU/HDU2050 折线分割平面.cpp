#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e4+5;
ll dp[maxn]={1,2};
int main()
{
    for(int i=2;i<maxn;i++)
        dp[i]=dp[i-1]+4*i-3;
    int t,x;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&x);
        printf("%lld\n",dp[x]);
    }
}