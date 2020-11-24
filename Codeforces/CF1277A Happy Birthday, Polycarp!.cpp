#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int t; ll n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        ll tmp=1,ans=0;
        for(int i=1;i<=10;i++)
        {
            if(n>=tmp*10) ans+=9;
            else break;
            tmp=tmp*10+1;
        }
        ans+=n/tmp;
        cout<<ans<<endl;
    }
}