#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1e6+5;
int a[maxn];
struct libasis
{
    int bas[32]; int pos[32];
    void insert(int p,int x)
    {
        for(int i=30;i>=0;i--)
            if(x&(1LL<<i))
            {
                if(!bas[i]) 
                {    bas[i]=x,pos[i]=p; return; }
                if(pos[i]<p)
                    swap(bas[i],x),swap(pos[i],p);
                x^=bas[i];
            }
    }
    int getmax(int l)
    {
        int ans=0;
        for(int i=30;i>=0;i--)
            if(pos[i]>=l&&!(ans&(1LL<<i)))
                ans^=bas[i];
        return ans;
    }
}lb[maxn];
int query(int l,int r)
{    return lb[r].getmax(l); }
void update(int id,int x)
{    lb[id]=lb[id-1],lb[id].insert(id,x); }
int main()
{
    int t,n,m,o,x,l,r;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]),update(i,a[i]);
        int ans=0;
        for(int i=1;i<=m;i++)
        {
            scanf("%d",&o);
            if(o==1) scanf("%d",&x),update(++n,x^ans);
            if(o==0) 
            {
                scanf("%d%d",&l,&r);
                l=(l^ans)%n+1,r=(r^ans)%n+1;
                if(l>r) swap(l,r);
                ans=query(l,r);
                printf("%d\n",ans);
            }
        }
    }
}