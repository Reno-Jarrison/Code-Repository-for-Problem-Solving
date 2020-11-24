#include<iostream>
using namespace std;
int a[1005],b[1005];
int gcd(int a,int b)
{    return !b?a:gcd(b,a%b); }
int lcm(int a,int b)
{    return a/gcd(a,b)*b; }
int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<n;i++)
            b[i]=lcm(a[i],a[i+1]);
        b[0]=a[1],b[n]=a[n];
        for(int i=0;i<=n;i++)
            cout<<b[i]<<" ";
        puts("");
    }
}