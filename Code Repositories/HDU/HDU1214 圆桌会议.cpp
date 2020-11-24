#include<bits/stdc++.h>
using namespace std;
int c2(int x)
{    return x*(x-1)/2; }
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        int x=n/2,y=n-x;
        printf("%d\n",c2(x)+c2(y));
    }
}    