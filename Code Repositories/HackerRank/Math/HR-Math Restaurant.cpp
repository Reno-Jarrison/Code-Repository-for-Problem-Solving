#include<iostream>
using namespace std;
int gcd(int a,int b)
{    return !a?b:gcd(b%a,a); }
inline int sqr(int x)
{    return x*x; }
int main()
{
    int t,a,b;
    cin>>t;
    while(t--)
    {
        cin>>a>>b;
        cout<<a*b/sqr(gcd(a,b))<<endl;
    }
}