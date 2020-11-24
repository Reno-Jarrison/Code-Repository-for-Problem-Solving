#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int f[maxn],w[maxn];
int find(int x)
{
    if(x!=f[x])
    {
        int rt=find(f[x]);
        w[x]+=w[f[x]],f[x]=rt;
    }
    return f[x];
}
int main()
{
    int n,m,a,b,s;
    while(~scanf("%d%d",&n,&m))
    {
        int ans=0;
        for(int i=0;i<=n;i++) 
            f[i]=i,w[i]=0;
        for(int i=1;i<=m;i++)
        {
            scanf("%d%d%d",&a,&b,&s),a--;
            int fa=find(a),fb=find(b);
            if(fa!=fb) f[fb]=fa,w[fb]=s+w[a]-w[b];
            else if(w[b]-w[a]!=s) ans++;
        }
        printf("%d\n",ans);
    }
}