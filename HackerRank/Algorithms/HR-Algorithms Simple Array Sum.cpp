#include<iostream>
using namespace std;
int main()
{
    int n,x,ans=0;
    cin>>n;
    for(int i=1;i<=n;i++) 
    	cin>>x,ans+=x;
    cout<<ans;
}