#include<iostream>
#define ll long long
using namespace std;
int main()
{
    int q;
    ll k,mod,a,b;
    cin>>q;
    while(q--)
    {
        cin>>a>>b>>k>>mod;
        ll c=1,d=0;
        while(k)
        {
            if(k&1)
            {
                ll tc=(a*c%mod-b*d%mod+mod)%mod;
                ll td=(a*d%mod+b*c%mod)%mod;
                c=tc,d=td;
            }
            ll ta=(a*a%mod-b*b%mod+mod)%mod;
            ll tb=2LL*a*b%mod;
            a=ta,b=tb,k>>=1;
        }
        cout<<c<<" "<<d<<endl;
    }
}