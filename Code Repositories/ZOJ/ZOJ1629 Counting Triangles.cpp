#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll dp[505],cur[505];
void init(int n)
{
    for(int i=1;i<=n;i++)
    {
        cur[i]=cur[i-1]+i/2;
        dp[i]=dp[i-1]+(i+1)*i/2+cur[i];
    }
}
int main()
{
    init(500);
    int n;
    while(~scanf("%d",&n))
        printf("%lld\n",dp[n]);
}