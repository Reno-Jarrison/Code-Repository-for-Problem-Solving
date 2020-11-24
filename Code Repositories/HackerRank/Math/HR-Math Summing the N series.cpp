#include<iostream>
#define ll long long
#define sqr(x) ((x)*(x))
const ll mod=1e9+7;
using namespace std;
int main()
{
    int t; ll x;
    cin>>t;
    while(t--) cin>>x,cout<<sqr(x%mod)%mod<<endl;
}