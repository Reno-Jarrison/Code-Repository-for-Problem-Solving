#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
char s[maxn];
int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%s",&n,s+1);
        int las=-1,cnt[2]={0};
        for(int i=1;i<=n;i++)
        {
            int cur=s[i]-'0';
            if(cur==las) cnt[cur]++;
            las=cur;
        }
        printf("%d\n",max(cnt[0],cnt[1]));
    }
}