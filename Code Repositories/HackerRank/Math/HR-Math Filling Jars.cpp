#include<iostream>
using namespace std;
int main()
{
    int n,m,a,b,k;
    long long ans=0;
    cin>>n>>m;
    while(m--)
    {
        cin>>a>>b>>k;
        ans+=1LL*(b-a+1)*k;
    }
    cout<<ans/n;
}