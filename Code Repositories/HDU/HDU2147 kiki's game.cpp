#include<cstdio>
using namespace std;
int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m)&&n&&m)
        puts((n&1)&&(m&1)?"What a pity!":"Wonderful!");
}