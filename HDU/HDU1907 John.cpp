#include<cstdio>
using namespace std;
int main()
{
    int t,n,x;
    scanf("%d",&t);
    while(t--)
    {
        int sum=0,flag=1;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",&x),sum^=x,flag&=(x==1);
        puts((flag&&sum)||(!flag&&!sum)?"Brother":"John");
    }
}