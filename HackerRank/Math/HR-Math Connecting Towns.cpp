#include<iostream>
#define ll long long
const ll mod=1234567;
using namespace std;
int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        ll ans=1,x;
        for(int i=1;i<n;i++)
            cin>>x,ans=ans*x%mod;
        cout<<ans<<endl;
    }
}