#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+5;
int d[maxn];
int main()
{
    int t,n,m,u,v,fst=1;
    scanf("%d",&t);
    while(t--)
    {
        if(fst) fst=0;
        else puts("");
        scanf("%d%d",&n,&m);
        fill(d+1,d+n+1,0);
        for(int i=1;i<=m;i++)
            scanf("%d%d",&u,&v),d[u]++,d[v]++;
        long long ans=0;     
        for(int i=1;i<=n;i++)
            ans+=d[i]*d[i];
        printf("%lld\n",ans);
    }
}