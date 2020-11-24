#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
struct node
{    int idx[24],step; };
int getans(int *id)
{
    int ans=0;
    if(id[0]==id[1]&&id[1]==id[2]&&id[2]==id[3]) ans++;
    if(id[4]==id[5]&&id[5]==id[10]&&id[10]==id[11]) ans++;
    if(id[6]==id[7]&&id[7]==id[12]&&id[12]==id[13]) ans++;
    if(id[8]==id[9]&&id[9]==id[14]&&id[14]==id[15]) ans++;
    if(id[16]==id[17]&&id[17]==id[18]&&id[18]==id[19]) ans++;
    if(id[20]==id[21]&&id[21]==id[22]&&id[22]==id[23]) ans++;
    return ans;
}
void swap(int *id,int a,int b,int c,int d)
{    int tmp=id[d]; id[d]=id[c],id[c]=id[b],id[b]=id[a],id[a]=tmp; }
void fswap(int *id)
{
    swap(id,18,19,17,16);
    swap(id,20,15,13,11);
    swap(id,21,14,12,10);
}
void rswap(int *id)
{
    swap(id,9,15,14,8);
    swap(id,3,23,19,13);
    swap(id,1,21,17,7);
}
void bswap(int *id)
{
    swap(id,6,12,13,7);
    swap(id,5,16,14,3);
    swap(id,2,11,17,8);
}
int bfs(node beg,int end)
{
    queue<node>q;
    q.push(beg);
    int ans=getans(beg.idx);
    while(!q.empty())
    {
        node now=q.front(); q.pop();
        ans=max(ans,getans(now.idx));
        now.step++;
        if(now.step>end) continue;
        node nxt1=now;
        fswap(nxt1.idx),q.push(nxt1);
        fswap(nxt1.idx),fswap(nxt1.idx),q.push(nxt1);
        node nxt2=now;
        rswap(nxt2.idx),q.push(nxt2);
        rswap(nxt2.idx),rswap(nxt2.idx),q.push(nxt2);
        node nxt3=now;
        bswap(nxt3.idx),q.push(nxt3);
        bswap(nxt3.idx),bswap(nxt3.idx),q.push(nxt3);
    }
    return ans; 
}
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        node tmp;
        for(int i=0;i<24;i++)
            scanf("%d",&tmp.idx[i]);
        tmp.step=0;
        printf("%d\n",bfs(tmp,n));
    } 
}