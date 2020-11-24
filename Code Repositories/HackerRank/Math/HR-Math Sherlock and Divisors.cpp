#include<iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,ans=1;
        cin>>n;
        if(n&1) { cout<<0<<endl; continue; }
        n>>=1;
        for(int i=2;i*i<=n;i++)
            if(n%i==0)
            {
                int cnt=1;
                while(n%i==0) n/=i,cnt++;
                ans*=cnt;
            }
        if(n>1) ans<<=1;
        cout<<ans<<endl;
    }
}