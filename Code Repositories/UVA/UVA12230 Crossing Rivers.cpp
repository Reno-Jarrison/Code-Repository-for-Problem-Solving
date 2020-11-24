#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int main()
{
    int n,d,p,l,v,cases=0;
    while(~scanf("%d%d",&n,&d)&&d)
    {
        double ans=d;
        for(int i=1;i<=n;i++)
            scanf("%d%d%d",&p,&l,&v),ans+=2.0*l/v-l;
        printf("Case %d: %.3lf\n",++cases,ans);
        puts("");
    }    
}