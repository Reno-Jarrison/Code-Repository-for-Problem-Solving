#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
bool cmp(int x,int y)
{
    int sx=0,sy=0,tx=x,ty=y;
    while(tx) sx+=tx%10,tx/=10;
    while(ty) sy+=ty%10,ty/=10;
    return sx<sy||(sx==sy&&x>y);
}
int main()
{
    int n,cnt=0,p[200];
    cin>>n;
    for(int i=1;i<=n;i++)
        if(n%i==0) p[++cnt]=i;
    sort(p+1,p+cnt+1,cmp);
    cout<<p[cnt];
}