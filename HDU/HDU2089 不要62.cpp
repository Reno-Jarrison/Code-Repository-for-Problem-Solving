#include<cstdio>
#include<cstring>
using namespace std;
int num[10],dp[10][2];
int dfs(int pos,bool las,bool lim)
{
    if(!pos) return 1;
    if(!lim&&~dp[pos][las]) return dp[pos][las];
    int bound=lim?num[pos]:9,ans=0;
    for(int i=0;i<=bound;i++)
    {
        if(i==4||(las&&i==2)) continue;
        ans+=dfs(pos-1,i==6,lim&&i==bound);
    }
    if(!lim) dp[pos][las]=ans;
    return ans;
}
int query(int x)
{
    int len=0;
    while(x) num[++len]=x%10,x/=10;
    return dfs(len,false,true);
}
int main()
{
    int l,r;
    memset(dp,-1,sizeof(dp));
    while(scanf("%d%d",&l,&r)&&l)
        printf("%d\n",query(r)-query(l-1));
}