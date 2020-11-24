#include<cstdio>
using namespace std;
int main()
{
    int t,x;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&x),x++;
        printf("%d\n",x/2+1);
    }
}