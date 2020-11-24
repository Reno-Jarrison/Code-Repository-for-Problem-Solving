#include<cstdio>
using namespace std;
int main()
{
    int n,x;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&x);
        if(x>=38&&(x/5+1)*5-x<3) x=(x/5+1)*5;
        printf("%d\n",x);
    }
}