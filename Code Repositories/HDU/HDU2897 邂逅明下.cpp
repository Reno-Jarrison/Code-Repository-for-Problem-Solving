#include<cstdio>
using namespace std;
int main()
{
    int n,p,q;
    while(~scanf("%d%d%d",&n,&p,&q))
        puts(n%(p+q)>0&&n%(p+q)<=p?"LOST":"WIN");
}