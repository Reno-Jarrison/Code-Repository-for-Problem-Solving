#include<cstdio>
using namespace std;
int main()
{
    int t,s,k;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&s,&k);
        int ans=0;
        if((k&1)==0)
        {
            int tmp=s%(k+1);
            if(tmp==k) ans=k;
            else ans=tmp&1;
        }
        else ans=s&1;
        printf("%d\n",ans);
    }
}