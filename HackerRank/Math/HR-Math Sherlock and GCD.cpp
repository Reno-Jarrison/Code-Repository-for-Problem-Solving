#include<iostream>
using namespace std;
int gcd(int a,int b)
{    return !b?a:gcd(b,a%b); }
int main()
{
    int t,n,x,d;
    cin>>t;
    while(t--)
    {
        cin>>n>>d;
        while(--n) 
            cin>>x,d=gcd(d,x); 
        puts(d==1?"YES":"NO");
    }
}