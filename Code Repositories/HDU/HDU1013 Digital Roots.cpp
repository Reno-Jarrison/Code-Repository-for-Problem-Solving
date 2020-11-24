#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
char s[maxn];
int main()
{
    while(scanf("%s",s))
    {
        if(s[0]=='0') break;
        int len=strlen(s),sum=0;
        for(int i=0;i<len;i++)
            sum=(sum*10+s[i]-'0')%9;
        if(!sum) sum=9;
        printf("%d\n",sum);
    }
}