#include<bits/stdc++.h>
using namespace std;
const int maxn=805,inf=0x3f3f3f3f;
int src[maxn][maxn];
struct node
{
    int mnv,mxv;
    node(int mnv=inf,int mxv=0):mnv(mnv),mxv(mxv){}
    void merge(node x)
    {    mnv=min(mnv,x.mnv),mxv=max(mxv,x.mxv); }
};
struct Quadtree
{
    int mnv[maxn*maxn*16],mxv[maxn*maxn*16];
    void push_up(int rt,int rt0,int rt1,int rt2,int rt3)
    {
        mnv[rt]=inf,mxv[rt]=0;
        mnv[rt]=min(mnv[rt],mnv[rt0]),mxv[rt]=max(mxv[rt],mxv[rt0]);
        mnv[rt]=min(mnv[rt],mnv[rt1]),mxv[rt]=max(mxv[rt],mxv[rt1]);
        mnv[rt]=min(mnv[rt],mnv[rt2]),mxv[rt]=max(mxv[rt],mxv[rt2]);
        mnv[rt]=min(mnv[rt],mnv[rt3]),mxv[rt]=max(mxv[rt],mxv[rt3]);
    }
    void build(int rt,int xl,int xr,int yl,int yr)
    {
        mnv[rt]=inf,mxv[rt]=0;
        if(xl>xr||yl>yr) return;
        if(xl==xr&&yl==yr)
        {    mnv[rt]=mxv[rt]=src[xl][yl]; return; }
        int xmid=(xl+xr)>>1,ymid=(yl+yr)>>1;
        int rt0=rt<<2,rt1=rt0|1,rt2=rt0|2,rt3=rt0|3;
        build(rt0,xl,xmid,yl,ymid);
        build(rt1,xl,xmid,ymid+1,yr);
        build(rt2,xmid+1,xr,yl,ymid);
        build(rt3,xmid+1,xr,ymid+1,yr);
        push_up(rt,rt0,rt1,rt2,rt3);
    }
    void update(int rt,int xl,int xr,int yl,int yr,int posx,int posy,int val)
    {
        if(xl>xr||yl>yr) return;
        if(xl==xr&&yl==yr) { mnv[rt]=mxv[rt]=val; return; }
        int xmid=(xl+xr)>>1,ymid=(yl+yr)>>1;
        int rt0=rt<<2,rt1=rt0|1,rt2=rt0|2,rt3=rt0|3;
        if(posx<=xmid&&posy<=ymid) update(rt0,xl,xmid,yl,ymid,posx,posy,val);
        if(posx<=xmid&&posy>ymid) update(rt1,xl,xmid,ymid+1,yr,posx,posy,val);
        if(posx>xmid&&posy<=ymid) update(rt2,xmid+1,xr,yl,ymid,posx,posy,val);
        if(posx>xmid&&posy>ymid) update(rt3,xmid+1,xr,ymid+1,yr,posx,posy,val);
        push_up(rt,rt0,rt1,rt2,rt3);
    }
    node query(int rt,int xl,int xr,int yl,int yr,int xL,int xR,int yL,int yR)
    {
        if(xl>xr||yl>yr) return node();
        if(xL<=xl&&xr<=xR&&yL<=yl&&yr<=yR)
            return node(mnv[rt],mxv[rt]);
        int xmid=(xl+xr)>>1,ymid=(yl+yr)>>1;
        int rt0=rt<<2,rt1=rt0|1,rt2=rt0|2,rt3=rt0|3;
        node ans;
        if(xL<=xmid&&yL<=ymid) ans.merge(query(rt0,xl,xmid,yl,ymid,xL,xR,yL,yR));
        if(xL<=xmid&&yR>ymid) ans.merge(query(rt1,xl,xmid,ymid+1,yr,xL,xR,yL,yR));
        if(xR>xmid&&yL<=ymid) ans.merge(query(rt2,xmid+1,xr,yl,ymid,xL,xR,yL,yR));
        if(xR>xmid&&yR>ymid) ans.merge(query(rt3,xmid+1,xr,ymid+1,yr,xL,xR,yL,yR));
        return ans;
    }
}t;
int main()
{
    int T,n,m,x,y,len,ks=0;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                scanf("%d",&src[i][j]);
        t.build(1,1,n,1,n);
        scanf("%d",&m);
        printf("Case #%d:\n",++ks);
        for(int i=1;i<=m;i++)
        {
            scanf("%d%d%d",&x,&y,&len),len/=2;
            int xl=max(x-len,1),xr=min(x+len,n);
            int yl=max(y-len,1),yr=min(y+len,n);
            node ans=t.query(1,1,n,1,n,xl,xr,yl,yr);
            int val=(ans.mxv+ans.mnv)/2;
            printf("%d\n",val);
            t.update(1,1,n,1,n,x,y,val);
        }
    }
}
