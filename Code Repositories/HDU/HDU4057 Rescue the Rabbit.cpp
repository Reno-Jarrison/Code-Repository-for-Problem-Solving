#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+5,inf=0x3f3f3f3f;
char s[105],pat[5]="ATGC";
bool dp[2][maxn][1<<10];
int w[15],val[1<<10];
int h(char ch)
{    
    for(int i=0;i<4;i++)
        if(ch==pat[i]) return i;
}
void getval(int n)
{
    for(int i=0;i<(1<<n);i++)
    {
        val[i]=0;
        for(int j=0,k=i;k;j++,k>>=1)
            if(k&1) val[i]+=w[j];
    }
}
int cal(int x)
{
    int ans=0;
    for(int i=0;x;i++,x>>=1)
        if(x&1) ans+=w[i];
    return ans;
}
struct ACAM
{
    int tot,tag[maxn],nxt[maxn][4],fail[maxn];
    void init()
    {    tot=0,newnode(); }
    int newnode()
    {    
        memset(nxt[tot],0,sizeof(nxt[tot]));
        return tag[tot]=fail[tot]=0,tot++;
    }
    void insert(char *s,int id)
    {
        int len=strlen(s),pt=0;
        for(int i=0;i<len;i++)
        {
            int to=h(s[i]);
            if(!nxt[pt][to])
                nxt[pt][to]=newnode();
            pt=nxt[pt][to];
        }
        tag[pt]|=1<<id;
    }
    void getfail()
    {
        queue<int>que;
        for(int i=0;i<4;i++)
            if(nxt[0][i]) que.push(nxt[0][i]);
        while(!que.empty())
        {
            int u=que.front();
            tag[u]|=tag[fail[u]];
            que.pop();
            for(int i=0;i<4;i++)
            {
                int v=nxt[u][i],f=fail[u];
                if(v) fail[v]=nxt[f][i],que.push(v);
                else nxt[u][i]=nxt[f][i];
            }
        }
    }
    void solve(int n,int m)
    {
        memset(dp,0,sizeof(dp));
        dp[0][0][0]=1;
        getval(n);
        int cur=0;
        for(int i=0;i<m;i++,cur^=1)
        {
            memset(dp[cur^1],0,sizeof(dp[cur^1]));
            for(int j=0;j<tot;j++)
                for(int k=0;k<(1<<n);k++)
                {
                    if(!dp[cur][j][k]) continue;
                    for(int l=0;l<4;l++)
                    {
                        int to=nxt[j][l];
                        dp[cur^1][to][k|tag[to]]=1;
                    }
                }
        }
        int ans=-inf;
        for(int i=0;i<tot;i++)
            for(int j=0;j<(1<<n);j++)
                if(dp[cur][i][j])
                    ans=max(ans,val[j]);
        if(ans>=0) printf("%d\n",ans);
        else puts("No Rabbit after 2012!");
    }
}acam;
int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        acam.init();
        for(int i=0;i<n;i++)
            scanf("%s%d",s,&w[i]),acam.insert(s,i);
        acam.getfail(),acam.solve(n,m);
    }
}