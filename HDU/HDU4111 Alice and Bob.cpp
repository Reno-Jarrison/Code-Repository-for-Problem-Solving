#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=5e4+5;
int sg[55][maxn];
bool getsg(int a,int b)
{
    if(sg[a][b]!=-1) return sg[a][b];
    if(b==1) return getsg(a+1,0);
    if(!a) return b&1;
    int &ans=sg[a][b];
    ans=0;
    if(a&&!getsg(a-1,b)) ans=1;
    else if(b&&!getsg(a,b-1)) ans=1;
    else if(a&&b&&!getsg(a-1,b+1)) ans=1;
    else if(a>=2&&!getsg(a-2,b?b+3:b+2)) ans=1;
    return ans;
}
int main()
{
    int t,n,cases=0;
    memset(sg,-1,sizeof(sg));
    scanf("%d",&t);
    while(t--)
    {
        int a=0,b=0,x;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",&x),x==1?a++:b+=x+1;
        if(b) b--;
        printf("Case #%d: %s\n",++cases,getsg(a,b)?"Alice":"Bob");
    }
}