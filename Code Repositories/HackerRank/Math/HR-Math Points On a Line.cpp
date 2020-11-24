#include<iostream>
using namespace std;
int main()
{
    int n,x,y,a,b;
    bool xflag=true,yflag=true;
    cin>>n>>x>>y;
    while(--n)
    {
        cin>>a>>b;
        if(a!=x) xflag=false;
        if(b!=y) yflag=false;
    }
    puts(xflag|yflag?"YES":"NO");
}