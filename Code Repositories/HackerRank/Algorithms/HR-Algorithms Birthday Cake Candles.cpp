#include<cstdio>
using namespace std;
int main()
{
    int n,x,mxv=0,ans=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&x);
        if(x>mxv) mxv=x,ans=0;
        if(x==mxv) ans++;
    }
    printf("%d",ans);
}