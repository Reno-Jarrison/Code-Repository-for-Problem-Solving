#include<iostream>
#define inf 0x3f3f3f3f
using namespace std;
int main()
{
    int n,a,b,x=inf,y=inf;
    cin>>n;
    while(n--)
    {
        cin>>a>>b;
        x=min(a,x);
        y=min(b,y);
    }
    cout<<1LL*x*y;
}