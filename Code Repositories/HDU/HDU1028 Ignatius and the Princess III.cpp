#include<cstdio>
#include<cstring>
#define ll long long
using namespace std;
const int maxn=125;
ll dp[maxn][maxn];
ll f(int n,int m)
{
    if(!n) return 1;
    if(!m||n<0) return 0;
    if(dp[n][m]!=-1) return dp[n][m];
    return dp[n][m]=f(n,m-1)+f(n-m,m);
}
int main()
{
    int n;
    memset(dp,-1,sizeof(dp));
    while(~scanf("%d",&n))
        printf("%lld\n",f(n,n));
}