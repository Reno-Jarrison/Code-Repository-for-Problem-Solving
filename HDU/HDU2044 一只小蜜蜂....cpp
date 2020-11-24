#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=60;
ll dp[maxn]={1,1};
int main()
{
    int t,a,b;
    for(int i=2;i<maxn;i++)
        dp[i]=dp[i-1]+dp[i-2];
    dp[0]=0;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&a,&b);
        printf("%lld\n",dp[max(0,b-a)]);
    }
}