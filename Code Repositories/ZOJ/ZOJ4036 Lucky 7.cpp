#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T,n,a,b;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&b);
        int ok=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a);
            if((a+b)%7==0) ok=1;
        }
        puts(ok?"Yes":"No");
    }
}