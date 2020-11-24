#include<iostream>
using namespace std;
int main()
{
    int t,n,k;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        if(k<n/2) cout<<k*2+1<<endl;
        else cout<<(n-k-1)*2<<endl;
    }
}