#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn=105;
char a[maxn],b[maxn];
int dp[maxn][maxn],p1[maxn],p2[maxn];
int main()
{
    while(~scanf("%s%s",a+1,b+1))
    {
        int n=strlen(a+1),m=strlen(b+1);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                if(a[i]==b[j]) dp[i][j]=dp[i-1][j-1]+1;
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        int pt1=n,pt2=m,pos=dp[n][m];
        while(pt1&&pt2&&pos)
        {
            if(dp[pt1-1][pt2-1]+1==dp[pt1][pt2]&&a[pt1]==b[pt2])
                p1[pos]=pt1,p2[pos]=pt2,pt1--,pt2--,pos--;
            else if(dp[pt1-1][pt2]>dp[pt1][pt2-1]) pt1--;
            else pt2--;
        }
        pos=dp[n][m]+1;
        p1[pos]=n+1,p2[pos]=m+1;
        for(int i=1;i<=pos;i++)
        {
            for(int j=p1[i-1]+1;j<p1[i];j++) putchar(a[j]);
            for(int j=p2[i-1]+1;j<p2[i];j++) putchar(b[j]);
            if(i<pos) putchar(a[p1[i]]);
        }
        puts("");
    }
}