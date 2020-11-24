#include<cstdio>
using namespace std;
int main()
{
    int t,n,m;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        puts(n%(m+1)?"first":"second");
    }
}