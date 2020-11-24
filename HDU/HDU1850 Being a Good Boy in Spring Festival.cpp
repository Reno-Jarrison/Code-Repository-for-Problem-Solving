#include<cstdio>
using namespace std;
int a[105];
int main()
{
    int n;
    while(scanf("%d",&n)&&n)
    {
        int sum=0,ans=0;
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]),sum^=a[i];
        if(sum) for(int i=1;i<=n;i++)
            if(a[i]>=(sum^a[i])) ans++;
        printf("%d\n",ans);
    }
}