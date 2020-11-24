#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5;
int nxt[10],las[10],vis[maxn],num[5];
queue<pair<int,int>>que;
int tonum()
{
    int ans=0;
    for(int i=0;i<4;i++)
        ans=ans*10+num[i];
    return ans;
}
void init()
{
    for(int i=1;i<10;i++) 
        nxt[i]=i+1,las[i]=i-1;
    nxt[9]=1,las[1]=9;
}
void push(int x,int step)
{
    if(vis[x]) return;
    que.push(make_pair(x,step)),vis[x]=1;
}
int bfs(int s,int t)
{
    while(!que.empty()) que.pop();
    memset(vis,0,sizeof(vis));
    que.push(make_pair(s,0));
    vis[s]=1;
    while(!que.empty())
    {
        auto cur=que.front(); que.pop();
        int u=cur.first,step=cur.second;
        if(u==t) return step;
        for(int i=0;i<4;i++)
            num[3-i]=u%10,u/=10;
        for(int i=0;i<4;i++)
        {
            num[i]=nxt[num[i]];
            push(tonum(),step+1);
            num[i]=las[num[i]];
            num[i]=las[num[i]];
            push(tonum(),step+1);
            num[i]=nxt[num[i]];
            if(!i) continue;
            swap(num[i],num[i-1]);
            push(tonum(),step+1);
            swap(num[i],num[i-1]);
        }
    }
    return 0;
}
int main()
{
    init();
    int t,n,m;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        printf("%d\n",bfs(n,m));
    }
}