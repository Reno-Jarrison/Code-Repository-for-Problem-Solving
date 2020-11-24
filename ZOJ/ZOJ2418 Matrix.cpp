#include<bits/stdc++.h>
using namespace std;
int n,a[7][7],sum[7],ans;
void dfs(int step)
{
    if(step==n)
    {
        int mxv=0;
        for(int i=0;i<n;i++)
            mxv=max(mxv,sum[i]);
        ans=min(ans,mxv);
        return;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            sum[j]+=a[step][(j+i)%n];
        dfs(step+1);
        for(int j=0;j<n;j++)
            sum[j]-=a[step][(j+i)%n];
    }
}
int main()
{
    while(scanf("%d",&n)&&~n)
    {
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                scanf("%d",&a[i][j]);
        ans=1e5,dfs(0);
        printf("%d\n",ans);
    }
}