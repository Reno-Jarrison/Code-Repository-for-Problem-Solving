#include<cstdio>
#include<vector>
#include<queue>
#include<string>
#include<iostream>
#include<cstring>
#define ll long long
using namespace std;
const int maxn=1e4+5;
int tag[10],vis[maxn];
struct node
{
    int r; string s;
    node(int r,string s):r(r),s(s){}
};
queue<node>q;
int main()
{
    int n,m,x,ks=0;
    while(~scanf("%d%d",&n,&m))
    {
        memset(tag,0,sizeof(tag));
        for(int i=1;i<=m;i++)
            scanf("%d",&x),tag[x]=1;
        vector<int>v;
        for(int i=0;i<=9;i++)
            if(!tag[i]) v.push_back(i);
        memset(vis,0,sizeof(vis));
        while(!q.empty()) q.pop();
        string tmp="";
        for(int i=1;i<=9;i++)
            if(!tag[i]&&!vis[i%n])
                q.push(node(i%n,tmp+(char)(i+'0'))),vis[i%n]=1;
        printf("Case %d: ",++ks);
        int ok=0;
        while(!q.empty())
        {
            node cur=q.front(); q.pop();
            if(!cur.r) { cout<<cur.s<<endl,ok=1; break; } 
            for(int x:v)
            {
                int nr=(10%n*cur.r%n+x)%n;
                if(vis[nr]) continue;
                vis[nr]=1;
                q.push(node(nr,cur.s+(char)(x+'0')));
            }
        }
        if(!ok) puts("-1");
    }
}