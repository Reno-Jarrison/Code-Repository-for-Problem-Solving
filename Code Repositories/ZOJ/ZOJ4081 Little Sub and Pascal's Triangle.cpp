#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        ll k;
        scanf("%lld",&k),k--;
        int cnt=0;
        while(k) cnt+=(k&1),k>>=1;
        printf("%lld\n",1LL<<cnt);
    }
}