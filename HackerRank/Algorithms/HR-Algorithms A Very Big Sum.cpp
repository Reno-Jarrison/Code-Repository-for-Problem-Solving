#include<iostream>
#include<cmath>
#define ll long long
using namespace std;
int main()
{
    int n; ll x,ans=0;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>x,ans+=x;
    cout<<ans;
}