#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=25;
ll dp[maxn]={0,0,1},fac[maxn]={1,1,2};
int main()
{
    for(int i=3;i<maxn;i++)
    {
        dp[i]=(i-1)*(dp[i-1]+dp[i-2]);
        fac[i]=fac[i-1]*i;
    }
    int t,x;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&x);
        printf("%.2lf%%\n",100.0*dp[x]/fac[x]);
    }
}