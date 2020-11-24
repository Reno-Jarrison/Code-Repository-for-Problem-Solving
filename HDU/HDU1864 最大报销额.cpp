#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=3e6+5;
int dp[maxn],w[35];
int main()
{
    int n,m,idx;
    double tmp; char ch;
    while(scanf("%lf%d",&tmp,&n)&&n)
    {
        int v=tmp*100,cnt=0;
        for(int i=1;i<=n;i++) 
        {
            scanf("%d",&m);
            int sum[3]={0},ok=1,s=0;
            for(int j=1;j<=m;j++)
            {
                scanf(" %c:%lf",&ch,&tmp);
                idx=ch-'A',tmp*=100,s+=tmp;
                if(idx>2||tmp>100000) ok=0;
                else sum[idx]+=tmp;
            }
            for(int i=0;i<3;i++)
                if(sum[i]>60000) ok=0;
            if(s>100000) ok=0;
            if(ok) w[++cnt]=s; 
        }
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=cnt;i++)
            for(int j=v;j>=w[i];j--)
                dp[j]=max(dp[j],dp[j-w[i]]+w[i]);
        printf("%.2lf\n",dp[v]/100.0);
    }
}