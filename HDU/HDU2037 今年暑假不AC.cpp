#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
struct node
{    int l,r; }p[maxn];
bool operator <(const node& x,const node& y)
{    return x.r<y.r; }
int main()
{
    int n;
    while(scanf("%d",&n)&&n)
    {
        for(int i=1;i<=n;i++)
            scanf("%d%d",&p[i].l,&p[i].r);
        sort(p+1,p+n+1);
        int ans=0,pt=0;
        for(int i=1;i<=n;i++)
            if(p[i].l>=pt)
                pt=p[i].r,ans++;
        printf("%d\n",ans);
    }
}