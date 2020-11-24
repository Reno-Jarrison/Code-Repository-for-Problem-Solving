#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn=1005;
char a[maxn],b[maxn];
int dp[maxn][maxn];
int main()
{
    while(~scanf("%s%s",a+1,b+1))
    {
        int n=strlen(a+1),m=strlen(b+1);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                if(a[i]==b[j]) dp[i][j]=dp[i-1][j-1]+1;
                else dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
        printf("%d\n",dp[n][m]);
    }
}