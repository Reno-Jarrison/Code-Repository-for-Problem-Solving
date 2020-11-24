#include<iostream>
#include<cmath>
using namespace std;
int gcd(int a,int b)
{    return !b?a:gcd(b,a%b); }
int main()
{
    int t,x1,x2,y1,y2;
    cin>>t;
    while(t--)
    {
        cin>>x1>>y1>>x2>>y2;
        cout<<gcd(abs(x1-x2),abs(y1-y2))-1<<endl;
    }
}