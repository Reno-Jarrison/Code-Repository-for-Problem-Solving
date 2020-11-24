#include<cstdio>
using namespace std;
const int maxn=1e4+5;
int dp[maxn];
int main()
{
    int n,m,k;
    while(scanf("%d%d%d",&n,&k,&m)==3&&n&&m&&k)
    {
        for(int i=2;i<=n;i++)
            dp[i]=(dp[i-1]+k)%i;
        int ans=((dp[n]+m-k)%n+n)%n+1;
        printf("%d\n",ans);
    }
}
