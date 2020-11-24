#include<cstdio>
using namespace std;
double ans[3];
int main()
{
    int n,x;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&x);
        ans[0]+=x>0,ans[1]+=x<0,ans[2]+=x==0;
    }
    for(int i=0;i<3;i++)
        printf("%.4lf\n",ans[i]/n);
}